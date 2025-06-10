#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int m, n;
  cin >> m >> n;

  vector<vi> dp(m + 5, vi(n + 5, 0));
  dp[0][0] = 1;

  FOR(u, 0, m + 1) {
    FOR(z, 0, n + 1) {
      if (u < m) (dp[u + 1][z] += dp[u][z] * (m - u)) %= MOD;
      if (z < n) (dp[u][z + 1] += dp[u][z]) %= MOD;
    }
  }
  ll ans = 0;
  FOR(u, 0, m + 1) {
    FOR(z, 0, n + 1) {
      if (u + z > 0 && u + z <= n) {
        (ans += dp[u][z]) %= MOD;
      }
    }
  }
  cout << ans << ENDL;

  return 0;
}