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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<pair<int, int>> pts(n);
  FOR(i, 0, n) { cin >> pts[i].second >> pts[i].first; }
  pts.pb({-1, -1});
  n = SZ(pts);
  sort(ALL(pts));
  FOR(i, 0, n) swap(pts[i].first, pts[i].second);
  pts[0] = {0, 0};
  vi dp(n, -1);
  auto solve = [&](auto self, int pos) -> int {
    if (pos == n) return 0;
    int& ans = dp[pos];
    if (ans != -1) return ans;
    ans = 0;
    FOR(i, pos + 1, n) {
      if (pts[i].first == pts[pos].first) {
        ans = max(ans, self(self, i) + 1);
        continue;
      }
      double m = (pts[i].second - pts[pos].second * 1.0) /
                 (pts[i].first - pts[pos].first * 1.0);
      if (abs(m) >= 1) ans = max(ans, self(self, i) + 1);
    }
    return ans;
  };
  int ans = 0;
  FOR(i, 0, n) ans = max(ans, solve(solve, i));
  cout << ans << ENDL;

  return 0;
}