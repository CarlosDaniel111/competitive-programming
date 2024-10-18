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

  int n;
  cin >> n;
  vector<vi> g(n);
  FOR(i, 1, n) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  vi depMax(n, 0);

  auto dfs = [&](auto self, int u, int p = -1) -> void {
    int hijos = 0;
    for (auto v : g[u]) {
      if (v == p) continue;
      self(self, v, u);
      hijos++;
    }

    if (hijos == 0) return;
    if (hijos == 1) {
      depMax[u] = 1;
      return;
    }
    int mn = 1e9, mx = 0;
    for (auto v : g[u]) {
      if (v == p) continue;
      mn = min(mn, depMax[v] + 1);
      mx = max(mx, depMax[v] + 1);
    }
    depMax[u] = min(mx, mn + 1);
  };

  auto dfs2 = [&](auto self, int u, int p = -1) -> void {
    for (auto v : g[u]) {
      if (v == p) continue;
      depMax[v] = min(depMax[v], depMax[u] - 1);
      self(self, v, u);
    }
  };

  dfs(dfs, 0);
  dfs2(dfs2, 0);
  int ans = 0;
  FOR(i, 0, n) if (depMax[i] < 0) ans++;
  cout << ans << ENDL;

  return 0;
}