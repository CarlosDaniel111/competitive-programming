#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;
  vector<vector<pi>> g(n);
  FOR(i, 0, n - 1) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].pb({v, w});
    g[v].pb({u, w});
  }

  vi dp(n, 0);
  auto dfs = [&](auto self, ll u, ll p) -> void {
    for (auto [v, w] : g[u]) {
      if (v == p) continue;
      self(self, v, u);
      dp[u] = max(dp[u], dp[v] + w);
    }
  };
  dfs(dfs, 0, -1);
  pi ans = {dp[0], 0};
  auto reroot = [&](auto self, ll u, ll p) -> void {
    ans = min(ans, {dp[u], u});
    for (auto [v, w] : g[u]) {
      if (v == p) continue;
      ll antU = dp[u], antV = dp[v];
      ll nU = 0;
      for (auto [v2, w2] : g[u]) {
        if (v2 == v) continue;
        nU = max(nU, dp[v2] + w2);
      }
      dp[u] = nU;
      dp[v] = max(dp[u] + w, dp[v]);
      self(self, v, u);
      dp[u] = antU, dp[v] = antV;
    }
  };
  reroot(reroot, 0, -1);
  cout << ans.second + 1 << " " << ans.first << ENDL;

  return 0;
}