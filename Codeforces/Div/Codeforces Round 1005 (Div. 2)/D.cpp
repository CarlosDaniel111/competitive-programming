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

int lg2(int x) {
  if (x == 0) return 0;
  return log2(x);
}

void solve() {
  int n, q;
  cin >> n >> q;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  vector<vi> dp(n + 5, vi(32, -1));
  auto solve = [&](auto self, int pos, int bit) -> int {
    if (pos < 0) return 0;
    int &ans = dp[pos][bit];
    if (ans != -1) return ans;
    if (lg2(a[pos]) >= bit) return ans = pos;
    return ans = self(self, pos - 1, bit);
  };

  vi suff(n + 1, 0);
  ROF(i, n, 0) { suff[i] = suff[i + 1] xor a[i]; }

  while (q--) {
    int x;
    cin >> x;
    int pos = n - 1;
    while (true) {
      int currx = suff[pos + 1] xor x;
      int sig = solve(solve, pos, lg2(currx));
      currx = suff[sig + 1] xor x;
      if (currx < a[sig]) {
        cout << n - sig - 1 << " ";
        break;
      }
      if (sig == 0) {
        cout << n << " ";
        break;
      }
      pos = sig - 1;
    }
  }
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}