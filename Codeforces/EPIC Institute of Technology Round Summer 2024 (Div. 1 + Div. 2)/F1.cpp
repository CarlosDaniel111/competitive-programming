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

vi a;
int dp[105][105][105];

int solve(int l, int r, int k) {
  if (l > r) return 0;
  int &ans = dp[l][r][k];
  if (ans != -1) return ans;
  ans = solve(l + 1, r, k);
  if (a[l] >= 0 && a[l] % 2 == 0 && a[l] / 2 <= k) {
    FOR(i, l + 1, r + 1) {
      int izq = solve(l + 1, i - 1, a[l] / 2);
      if (izq * 2 == (i - l - 1)) {
        int der = solve(i + 1, r, k + izq + 1);
        ans = max(ans, izq + der + 1);
      }
    }
  }
  return ans;
}

void solve() {
  memset(dp, -1, sizeof(dp));
  int n;
  cin >> n;
  a.resize(n);
  FOR(i, 0, n) {
    cin >> a[i];
    a[i]--;
    a[i] = i - a[i];
  }
  cout << solve(0, n - 1, 0) << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}