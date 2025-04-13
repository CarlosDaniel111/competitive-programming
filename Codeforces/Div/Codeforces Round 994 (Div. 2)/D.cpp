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
  ll n, m, k;
  cin >> n >> m >> k;
  vector<vi> a(n + 1, vi(m, 0));
  vector<vi> dp(n + 1, vi(m, 1e18));
  FOR(i, 1, n + 1) FOR(j, 0, m) cin >> a[i][j];

  dp[0][0] = 0;
  FOR(i, 1, n + 1) {
    FOR(shift, 0, m) {
      vi curr(m, 1e18);
      // abajo
      FOR(j, 0, m) curr[j] = dp[i - 1][j] + a[i][(j + shift) % m] + k * shift;
      // derecha
      FOR(j, 0, m)
      curr[j] = min(curr[j], curr[(j - 1 + m) % m] + a[i][(j + shift) % m]);
      FOR(j, 0, m) dp[i][j] = min(dp[i][j], curr[j]);
    }
  }
  cout << dp[n][m - 1] << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}