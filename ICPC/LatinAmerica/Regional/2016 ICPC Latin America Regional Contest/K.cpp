#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

template <typename T>
struct Dinic {
#define INF numeric_limits<T>::max()
  struct Edge {
    int to, rev;
    T c, oc;
    T flow() { return max(oc - c, T(0)); }  // if you need flows
  };
  vi lvl, ptr, q;
  vector<vector<Edge>> adj;
  Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
  void addEdge(int a, int b, T c, T rcap = 0) {
    adj[a].push_back({b, SZ(adj[b]), c, c});
    adj[b].push_back({a, SZ(adj[a]) - 1, rcap, rcap});
  }
  T dfs(int v, int t, T f) {
    if (v == t || !f) return f;
    for (int& i = ptr[v]; i < SZ(adj[v]); i++) {
      Edge& e = adj[v][i];
      if (lvl[e.to] == lvl[v] + 1)
        if (T p = dfs(e.to, t, min(f, e.c))) {
          e.c -= p, adj[e.to][e.rev].c += p;
          return p;
        }
    }
    return 0;
  }
  T calc(int s, int t) {
    T flow = 0;
    q[0] = s;
    FOR(L, 0, 31)
    do {  // 'int L=30' maybe faster for random data
      lvl = ptr = vi(SZ(q));
      int qi = 0, qe = lvl[s] = 1;
      while (qi < qe && !lvl[t]) {
        int v = q[qi++];
        for (Edge e : adj[v])
          if (!lvl[e.to] && e.c >> (30 - L)) q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
      }
      while (T p = dfs(s, t, INF)) flow += p;
    } while (lvl[t]);
    return flow;
  }
  bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<pi> a(n);
  FOR(i, 0, n) {
    cin >> a[i].first >> a[i].second;
    a[i].first--, a[i].second--;
  }

  int ans = 0;
  FOR(i, 0, n) {
    Dinic<int> d(n * 2 + 2);
    int s = n * 2, t = n * 2 + 1;
    int kill = 0;
    int tot = 0;
    FOR(j, 0, n) {
      if (i == j) continue;
      if (a[j].first == i || a[j].second == i) {
        kill++;
      } else {
        d.addEdge(j, a[j].first + n, 1);
        d.addEdge(j, a[j].second + n, 1);
        d.addEdge(s, j, 1);
        tot++;
      }
    }

    if (kill == 1) {
      ans++;
      continue;
    }

    FOR(j, 0, n) {
      if (i == j) continue;
      int flujo = kill - 1 - (a[i].first == j || a[i].second == j);
      d.addEdge(j + n, t, flujo);
    }

    if (d.calc(s, t) != tot) {
      ans++;
    }
  }
  cout << ans << ENDL;

  return 0;
}