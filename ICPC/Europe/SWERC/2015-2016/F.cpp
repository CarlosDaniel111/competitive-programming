// #include <bits/extc++.h>  // importante de incluir
#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

/**
 * Descripcion: algoritmo para calcular el flujo maximo en un grafo
 * Tiempo: O(V^2 E)
 */

struct Dinic {
  struct Edge {
    int to, rev;
    ll c, oc;
    ll flow() { return max(oc - c, 0LL); }  // if you need flows
  };
  vi lvl, ptr, q;
  vector<vector<Edge>> adj;
  Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
  void addEdge(int a, int b, ll c, ll rcap = 0) {
    adj[a].push_back({b, SZ(adj[b]), c, c});
    adj[b].push_back({a, SZ(adj[a]) - 1, rcap, rcap});
  }
  ll dfs(int v, int t, ll f) {
    if (v == t || !f) return f;
    for (int& i = ptr[v]; i < SZ(adj[v]); i++) {
      Edge& e = adj[v][i];
      if (lvl[e.to] == lvl[v] + 1)
        if (ll p = dfs(e.to, t, min(f, e.c))) {
          e.c -= p, adj[e.to][e.rev].c += p;
          return p;
        }
    }
    return 0;
  }
  ll calc(int s, int t) {
    ll flow = 0;
    q[0] = s;
    FOR(L, 0, 31)
    do {  // 'int L=30' maybe faster for random data
      lvl = ptr = vi(SZ(q));
      int qi = 0, qe = lvl[s] = 1;
      while (qi < qe && !lvl[t]) {
        int v = q[qi++];
        for (Edge e : adj[v])
          if (!lvl[e.to] && e.c >> (30 - L))
            q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
      }
      while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
    } while (lvl[t]);
    return flow;
  }
  bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

constexpr int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n, m, a, b;
  cin >> n >> m >> a >> b;
  vector<string> grid(n);
  FOR(i, 0, n) {
    cin >> grid[i];
  }

  ll source = 0, sink = n * m + 1;
  Dinic mf(n * m + 2);
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (grid[i][j] == '.')
        mf.addEdge(source, m * i + j + 1, b);
      else
        mf.addEdge(m * i + j + 1, sink, b);
      FOR(k, 0, 4) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m)
          mf.addEdge(m * i + j + 1, m * ni + nj + 1, a);
      }
    }
  }

  cout << mf.calc(source, sink) << ENDL;

  return 0;
}