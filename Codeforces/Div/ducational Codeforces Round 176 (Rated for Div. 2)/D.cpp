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

vector<vi> dp;

void solve() {
  ll x, y;
  cin >> x >> y;
  ll ans = 1e18;
  FOR(i, 0, 60) {
    FOR(j, 0, 60) {
      if (x >> i == y >> j) ans = min(ans, dp[i][j]);
    }
  }
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;

  dp.assign(65, vi(65, 1e18));
  dp[0][0] = 0;
  FOR(k, 1, 60) {
    ROF(i, 60, 0) {
      ROF(j, 60, 0) {
        if (i >= k) dp[i][j] = min(dp[i][j], dp[i - k][j] + (1ll << k));
        if (j >= k) dp[i][j] = min(dp[i][j], dp[i][j - k] + (1ll << k));
      }
    }
  }

  while (t--) solve();

  return 0;
}