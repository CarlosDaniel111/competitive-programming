#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  FOR(i, 1, n) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<pair<int, int>> ans;

  auto dfs = [&](auto self, int u, int p = -1) -> int {
    vector<int> libres;
    for (auto v : g[u])
      if (v != p) {
        int sobra = self(self, v, u);
        if (sobra != -1)
          libres.push_back(sobra);
        else
          libres.push_back(v);
      }
    for (int i = 0; i < SZ(libres) - 1; i += 2) {
      ans.push_back({libres[i], libres[i + 1]});
    }
    if (SZ(libres) & 1)
      return libres.back();
    else
      return -1;
  };
  int r = 0;
  FOR(i, 0, n) {
    if (SZ(g[i]) % 2 == 0) {
      r = i;
      break;
    }
  }
  int sobra = dfs(dfs, r);
  if (sobra != -1) {
    cout << -1 << '\n';
    return;
  }
  cout << SZ(ans) << '\n';
  for (auto [u, v] : ans) {
    cout << u + 1 << " " << v + 1 << '\n';
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}