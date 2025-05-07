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
  ll n, c;
  cin >> n >> c;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  vector<vi> g(n);
  FOR(i, 1, n) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  vector<vi> dp(n, vi(2, 0));
  auto dfs = [&](auto self, ll u, ll p = -1) -> void {
    dp[u][1] = a[u];
    for (auto v : g[u])
      if (v != p) {
        self(self, v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += max(dp[v][0], dp[v][1] - 2 * c);
      }
  };
  dfs(dfs, 0);
  cout << max(dp[0][0], dp[0][1]) << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}