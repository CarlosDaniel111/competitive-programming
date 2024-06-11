#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

constexpr ll MOD = 1e9 + 7;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, K;
  cin >> n >> K;
  vector<vi> dp(n + 5, vi(K + 5, 0));
  FOR(i, 1, n + 1) { dp[i][0] = 1; }
  FOR(i, 1, K) {
    FOR(j, 1, n + 1) {
      for (int k = j; k <= n; k += j) {
        dp[j][i] += dp[k][i - 1];
        dp[j][i] %= MOD;
      }
    }
  }

  ll ans = 0;
  FOR(i, 1, n + 1) {
    ans += dp[i][K - 1];
    ans %= MOD;
  }
  cout << ans << ENDL;

  return 0;
}