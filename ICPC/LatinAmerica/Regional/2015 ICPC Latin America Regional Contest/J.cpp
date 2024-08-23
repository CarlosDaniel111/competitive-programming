#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

constexpr ll MOD = 1e9 + 7;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<vi> dp(5005, vi(5005, 0));
  FOR(i, 0, 5001)
  dp[i][0] = 1;
  FOR(i, 1, 5001)
  FOR(j, 1, i + 1)
  dp[i][j] = ((j + 1) * dp[i - 1][j] + (i - j) * dp[i - 1][j - 1]) % MOD;

  ll n;
  cin >> n;
  vi ans(n + 1, 0);
  FOR(i, 1, n + 1) {
    ans[i] = (ans[i - 1] + dp[n][i - 1]) % MOD;
  }
  ll q;
  cin >> q;
  while (q--) {
    ll x;
    cin >> x;
    cout << ans[min(n, x)] << " ";
  }

  return 0;
}