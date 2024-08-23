#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
#define __                      \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);

signed main() {
  __ int n;
  cin >> n;
  vector<string> s(n);
  for (auto& si : s) cin >> si;

  vector<vector<ll>> dp(n, vector<ll>(4, 1e9));  // se me fue la cadrga
  auto solve = [&](auto self, int i, int mask) -> ll {
    if (i == n) return 0;
    ll& ans = dp[i][mask];
    if (ans != 1e9) return ans;

    int cnt = 0;
    FOR(j, 0, SZ(s[i])) {
      char c = s[i][j];
      if (c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U' && c != 'Y') {
        cnt++;
        if (cnt + mask > 2) break;
        if (cnt > 2) continue;
        ans = min(ans, j + 1 + self(self, i + 1, cnt + mask));
      } else {
        return ans = min(ans, j + 1 + self(self, i + 1, 0));
      }
    }
    return ans;  // si dio_?no
  };
  ll ans = solve(solve, 0, 0);
  if (ans >= 1e9) {
    cout << "*" << ENDL;
    return 0;
  }
  cout << ans << ENDL;  // l prefijoo  hsaiy que

  return 0;
}