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

constexpr ll MOD = 998244353;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  vector<vi> dp(n, vi(2, 0));
  vi sum(*max_element(ALL(a)) + 1, 0);
  dp[0][0] = 1;
  sum[a[0]] = 1;
  FOR(i, 1, n) {
    dp[i][0] = dp[i - 1][0] + dp[i - 1][1] % MOD;
    dp[i][1] = sum[a[i]];
    (sum[a[i]] += dp[i][0]) %= MOD;
  }
  cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << ENDL;

  return 0;
}