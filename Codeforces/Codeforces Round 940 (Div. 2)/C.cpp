#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define ROF(i, a, b) for (ll i = (ll)b - 1; i >= (ll)a; i--)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  FOR(i, 0, k) {
    int x, y;
    cin >> x >> y;
    if (x == y) {
      n--;
    } else {
      n -= 2;
    }
  }
  int dp[n + 2];
  dp[0] = dp[1] = 1;
  FOR(i, 2, n + 1) {
    dp[i] = (2 * (i - 1) % MOD * dp[i - 2] % MOD + dp[i - 1]) % MOD;
  }

  cout << dp[n] << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}