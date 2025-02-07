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

  ll n, m;
  cin >> n >> m;
  vector<vi> a(n + 5, vi(m + 5)), dp[4];
  FOR(i, 0, 4) dp[i].assign(n + 10, vi(m + 5, 0));

  FOR(i, 1, n + 1)
  FOR(j, 1, m + 1) cin >> a[i][j];

  FOR(i, 1, n + 1)
  FOR(j, 1, m + 1)
  dp[0][i][j] = a[i][j] + max(dp[0][i - 1][j], dp[0][i][j - 1]);

  FOR(i, 1, n + 1)
  ROF(j, m + 1, 1)
  dp[1][i][j] = a[i][j] + max(dp[1][i - 1][j], dp[1][i][j + 1]);

  ROF(i, n + 1, 1)
  FOR(j, 1, m + 1)  // cout << i << " " << j << ENDL;
  dp[2][i][j] = a[i][j] + max(dp[2][i + 1][j], dp[2][i][j - 1]);

  ROF(i, n + 1, 1)
  ROF(j, m + 1, 1)
  dp[3][i][j] = a[i][j] + max(dp[3][i + 1][j], dp[3][i][j + 1]);

  ll ans = 0;
  FOR(i, 2, n) {
    FOR(j, 2, m) {
      ans = max({ans,
                 dp[0][i - 1][j] + dp[1][i][j + 1] + dp[3][i + 1][j] +
                     dp[2][i][j - 1],
                 dp[1][i - 1][j] + dp[3][i][j + 1] + dp[2][i + 1][j] +
                     dp[0][i][j - 1]});
    }
  }
  cout << ans << ENDL;

  return 0;
}