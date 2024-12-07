#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

void solve() {
  ll n;
  cin >> n;
  vector<vi> g(n, vi());
  FOR(i, 1, n) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  vi dp(n, 0);
  ll ans = 0;
  auto dfs = [&](auto self, ll u, ll p) -> void {
    vi son;
    for (auto v : g[u]) {
      if (v == p) continue;
      self(self, v, u);
      son.pb(dp[v]);
    }
    sort(son.rbegin(), son.rend());
    ll noraiz = (u != 0);
    ans = max(ans, noraiz);
    if (SZ(son)) {
      dp[u] = max(SZ(son), son[0] + SZ(son) - 1);
      ans = max(ans, dp[u] + noraiz);
    }
    if (SZ(son) > 1) {
      ans = max(ans, son[0] + son[1] + SZ(son) - 2 + noraiz);
    }
  };
  dfs(dfs, 0, -1);
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}