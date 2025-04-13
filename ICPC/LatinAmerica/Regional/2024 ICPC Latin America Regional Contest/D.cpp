#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

pair<int, vi> hopcroftKarp(vector<vi>& g, int m) {
  int res = 0;
  vi btoa(m, -1), A(SZ(g)), B(m), cur, next;
  auto dfs = [&](auto self, int a, int L) -> bool {
    if (A[a] != L) return 0;
    A[a] = -1;
    for (int b : g[a])
      if (B[b] == L + 1) {
        B[b] = 0;
        if (btoa[b] == -1 || self(self, btoa[b], L + 1)) return btoa[b] = a, 1;
      }
    return 0;
  };
  while (1) {
    fill(ALL(A), 0);
    fill(ALL(B), 0);
    /// Encuentra los nodos restantes para BFS (i.e. con layer 0)
    cur.clear();
    for (int a : btoa)
      if (a != -1) A[a] = -1;
    FOR(a, 0, SZ(g)) if (A[a] == 0) cur.pb(a);
    /// Encunetra todas las layers usando BFS
    for (int lay = 1;; lay++) {
      bool islast = 0;
      next.clear();
      for (int a : cur)
        for (int b : g[a]) {
          if (btoa[b] == -1) {
            B[b] = lay;
            islast = 1;
          } else if (btoa[b] != a && !B[b]) {
            B[b] = lay;
            next.pb(btoa[b]);
          }
        }
      if (islast) break;
      if (next.empty()) return {res, btoa};
      for (int a : next) A[a] = lay;
      cur.swap(next);
    }
    /// Usa DFS para escanear caminos aumentantes
    FOR(a, 0, SZ(g)) res += dfs(dfs, a, 0);
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<vi> g(n, vi(n, 0));
  FOR(i, 0, n) {
    string s;
    cin >> s;
    FOR(j, 0, n) { g[i][j] = s[j] - '0'; }
  }
  vector<vi> id(n, vi(2, -1));
  int m;
  vector<vi> gb;
  vi vis(n, 0);

  auto dfs = [&](auto self, int u, int lado) -> void {
    vis[u] = 1;
    if (id[u][0] == -1) {
      id[u][0] = SZ(gb);
      gb.pb(vi());
    }
    if (id[u][1] == -1) {
      id[u][1] = m++;
    }
    gb[id[u][0]].pb(id[u][1]);

    vi izq, der;
    FOR(v, 0, n) {
      if (!g[u][v] or vis[v] or id[u][0] == id[v][0] or id[u][1] == id[v][1])
        continue;
      if (!SZ(izq) or g[izq.back()][v]) {
        izq.pb(v);
        id[v][lado] = id[u][lado];
      } else {
        der.pb(v);
        id[v][!lado] = id[u][!lado];
      }
    }

    for (auto v : izq)
      if (!vis[v]) self(self, v, !lado);
    for (auto v : der)
      if (!vis[v]) self(self, v, lado);
  };
  FOR(i, 0, n) {
    if (!vis[i]) {
      dfs(dfs, i, 0);
    }
  }
  auto [ans, _] = hopcroftKarp(gb, m);
  cout << ans << ENDL;

  return 0;
}