#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

constexpr int def = 100 * 100 + 5, mxdiff = def * 2 + 5;

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n;
  cin >> n;
  vi a(n);
  FOR (i, 0, n) {
    cin >> a[i];
  }

  vector<vector<bool>> dp(n + 1, vector<bool>(mxdiff));
  dp[n][def] = 1;
  ROF (i, n, 0) FOR (j, 0, mxdiff) dp[i][j] = (j - a[i] >= 0 && dp[i + 1][j - a[i]]) || (j + a[i] < mxdiff && dp[i + 1][j + a[i]]);

  if (!dp[0][def]) {
    cout << -1 << ENDL;
    return 0;
  }

  vi alice, bob;
  { 
    int curr = def;
    FOR (i, 0, n) {
      if (curr + a[i] < mxdiff && dp[i + 1][curr + a[i]]) {
        alice.pb(i);
        curr += a[i];
      }
      else if (curr - a[i] >= 0 && dp[i + 1][curr - a[i]]) {
        bob.pb(i);
        curr -= a[i];
      }
    }
  }

  int sa = 0, sb = 0, pa = 0, pb = 0;
  while (pa < SZ(alice) || pb < SZ(bob)) {
    if (sa <= sb) {
      sa += a[alice[pa]];
      cout << a[alice[pa++]] << ' ';
      continue;
    }
    sb += a[bob[pb]];
    cout << a[bob[pb++]] << ' ';
  }
  
  return 0;
}