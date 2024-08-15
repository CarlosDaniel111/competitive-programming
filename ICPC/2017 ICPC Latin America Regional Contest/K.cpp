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

constexpr int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  FOR(i, 0, n)
  cin >> grid[i];

  Dinic<int> mf(n * m + 2);
  int s = n * m;
  int t = n * m + 1;

  auto isValid = [&](int x, int y) -> bool {
    return (x >= 0 && x < n && y >= 0 && y < m);
  };

  int in = 0, out = 0;
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      int u = i * m + j;
      int f = (grid[i][j] == 'o' ? 1 : 2);
      if ((i + j) % 2) {
        mf.addEdge(s, u, f);
        in += f;
        FOR(k, 0, 4) {
          int i2 = i + dx[k], j2 = j + dy[k];
          if (!isValid(i2, j2)) continue;
          int v = i2 * m + j2;
          mf.addEdge(u, v, (grid[i][j] == 'o' ? 1 : 1e6));
        }
      } else {
        out += f;
        mf.addEdge(u, t, f);
      }
    }
  }

  int flow = mf.calc(s, t);
  cout << "NY"[in == out && flow == in] << ENDL;

  return 0;
}