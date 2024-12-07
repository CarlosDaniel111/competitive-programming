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
  vector<vector<pi>> g(n);
  FOR(i, 1, n) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    g[u].pb({v, w});
    g[v].pb({u, w});
  }
  vector<pi> dp(n, {1e9, -1});
  vi village(n, 0);

  auto dfs = [&](auto self, int u, int p = -1) -> void {
    if (SZ(g[u]) == 1) {
      dp[u] = {0, u};
    }
    for (auto [v, w] : g[u]) {
      if (v == p) continue;
      self(self, v, u);
      dp[u] = min(dp[u], {dp[v].first + w, dp[v].second});
    }
    village[dp[u].second]++;
  };
  dfs(dfs, 0);

  int q;
  cin >> q;
  vector<vector<pi>> querys(n);
  FOR(i, 0, q) {
    int s, t;
    cin >> s >> t;
    s--, t--;
    querys[t].pb({s, i});
  }

  vi ans(q, 0);

  auto reroot = [&](auto self, int u, int p = -1) -> void {
    for (auto [v, id] : querys[u]) {
      ans[id] = village[v];
    }

    for (auto [v, w] : g[u]) {
      if (v == p) continue;
      pi antU = dp[u], antV = dp[v];
      village[dp[u].second]--;
      village[dp[v].second]--;
      // v nuevo root
      pi nU = {1e9, -1};
      if (SZ(g[u]) == 1) {
        nU = {0, u};
      }
      for (auto [v2, w2] : g[u]) {
        if (v2 == v) continue;
        nU = min(nU, {dp[v2].first + w2, dp[v2].second});
      }
      dp[u] = nU;
      village[dp[u].second]++;
      dp[v] = min(dp[v], {dp[u].first + w, dp[u].second});
      village[dp[v].second]++;
      self(self, v, u);

      // regreso
      village[dp[u].second]--;
      village[dp[v].second]--;
      dp[u] = antU;
      dp[v] = antV;
      village[dp[u].second]++;
      village[dp[v].second]++;
    }
  };

  reroot(reroot, 0);

  FOR(i, 0, q) { cout << ans[i] << ENDL; }

  return 0;
}