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
  int n;
  cin >> n;
  vi a(n);
  int g = 0;
  FOR(i, 0, n) {
    cin >> a[i];
    g = gcd(g, a[i]);
  }
  int cnt = 0;
  FOR(i, 0, n) { cnt += (a[i] == g); }
  if (cnt) {
    cout << n - cnt << ENDL;
    return;
  }
  vector<vi> dp(n, vi(5005, -1));
  auto solve = [&](auto self, int i, int curr) -> int {
    if (curr == g) return 0;
    if (i >= n) return 1e9;
    int &ans = dp[i][curr];
    if (ans != -1) return ans;
    ans = self(self, i + 1, curr);
    ans = min(ans, self(self, i + 1, gcd(curr, a[i])) + 1);
    return ans;
  };

  cout << solve(solve, 0, 0) + n - 2 << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}