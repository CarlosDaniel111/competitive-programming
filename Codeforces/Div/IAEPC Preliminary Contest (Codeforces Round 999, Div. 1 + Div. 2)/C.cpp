#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

constexpr ll MOD = 998244353;

void solve() {
  int n;
  cin >> n;
  n++;
  vi a(n);
  a[0] = 0;
  FOR(i, 1, n) cin >> a[i];
  vi dp(n, 0);
  dp[0] = 1;
  FOR(i, 1, n) {
    if (a[i] == a[i - 1]) (dp[i] += dp[i - 1]) %= MOD;
    if (i >= 2 && a[i] == a[i - 2] + 1) (dp[i] += dp[i - 2]) %= MOD;
  }
  cout << (dp[n - 1] + dp[n - 2]) % MOD << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}