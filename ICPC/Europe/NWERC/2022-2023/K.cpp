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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int m, n;
  cin >> m >> n;
  vector<vi> g(n);
  FOR(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  vi util(n, 0);
  FOR(i, 0, n) {
    set<int> aux;
    for (auto v : g[i]) aux.insert(v);
    if (SZ(aux) > 1 or (SZ(aux) == 1 && aux.count(i))) util[i] = 1;
  }
  vi vis(n, 0);
  bool isCycle = true;
  auto dfs = [&](auto self, int u) -> bool {
    set<int> aux;
    for (auto v : g[u]) {
      if (!util[v] or v == u) continue;
      aux.insert(v);
      if (vis[v]) continue;
      vis[v] = true;
      if (!self(self, v)) return false;
    }
    if (SZ(aux) > 2) return false;
    if (SZ(aux) < 2) isCycle = false;
    return true;
  };

  int cycles = 0, paths = 0;
  FOR(i, 0, n) {
    if (!util[i] or vis[i]) continue;
    isCycle = true;
    if (!dfs(dfs, i)) {
      cout << "impossible" << ENDL;
      return 0;
    }
    if (isCycle)
      cycles++;
    else
      paths++;
  }
  if (cycles == 1) {
    if (paths) {
      cout << "impossible" << ENDL;
      return 0;
    }

    // hay tope?
    FOR(i, 0, n) {
      for (auto v : g[i]) {
        if (!util[i] && !util[v]) {
          cout << "impossible" << ENDL;
          return 0;
        }
      }
    }

    cout << "possible" << ENDL;
    return 0;
  }
  if (cycles > 1) {
    cout << "impossible" << ENDL;
    return 0;
  }
  cout << "possible" << ENDL;
  return 0;
}