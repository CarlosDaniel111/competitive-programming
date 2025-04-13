#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve() {
  int n, k;
  cin >> n >> k;
  vi a(n);
  FOR(i, 0, n) { cin >> a[i]; }

  auto can = [&](int x) -> bool {
    vi b(n);
    FOR(i, 0, n) {
      if (a[i] >= x) {
        b[i] = 1;
      } else {
        b[i] = -1;
      }
    }
    vi dp(n, 0);
    dp[0] = b[0];
    FOR(i, 1, n) {
      if (i % k == 0)
        dp[i] = max(dp[i - k], b[i]);
      else {
        dp[i] = dp[i - 1] + b[i];
        if (i > k) {
          dp[i] = max(dp[i], dp[i - k]);
        }
      }
    }
    return dp[n - 1] > 0;
  };

  int l = 1, r = 1e9;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (can(mid)) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << r << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}