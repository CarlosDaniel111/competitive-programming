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

constexpr ll MOD = 167772161;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, k;
  cin >> n >> k;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  vector<vi> dp(n + 1, vi(k + 1, 0));
  dp[0][0] = 1;

  FOR(i, 0, n) {
    ROF(j, k + 1, a[i]) {
      FOR(usado, 1, n) { (dp[usado][j] += dp[usado - 1][j - a[i]]) %= MOD; }
    }
  }

  FOR(i, 0, n) {
    vector<vi> currDP(n + 1, vi(k + 1, 0));
    FOR(usado, 0, n + 1) {
      FOR(kk, 0, k + 1) {
        if (usado == 0 or kk < a[i])
          currDP[usado][kk] = dp[usado][kk];
        else
          currDP[usado][kk] =
              (dp[usado][kk] - currDP[usado - 1][kk - a[i]] + MOD) % MOD;
      }
    }

    FOR(j, 1, n) {
      ll ans = 0;
      FOR(kk, k - a[i] + 1, k + 1) { (ans += currDP[j][kk]) %= MOD; }
      cout << ans << " ";
    }
    cout << ENDL;
  }

  return 0;
}