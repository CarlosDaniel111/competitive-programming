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

int dp[505][505][505];

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vi a;
  a.pb(0);
  FOR(i, 0, n) {
    string s;
    cin >> s;
    if (stoi(s) % 1111111 == 0) continue;
    int mx = 0, mxi = 0;
    FOR(i, 0, 7) {
      int curr = stoi(s);
      if (curr > mx) {
        mx = curr;
        mxi = i;
      }
      rotate(s.begin(), s.begin() + 1, s.end());
    }
    a.pb(mxi);
  }
  a.pb(0);
  vi cnt(10, 0);
  FOR(i, 1, SZ(a)) { cnt[(a[i] - a[i - 1] + 7) % 7]++; }

  int ans = max(cnt[1], cnt[6]) + max(cnt[2], cnt[5]) + max(cnt[3], cnt[4]);
  int x, cx, y, cy, z, cz;
  cx = abs(cnt[1] - cnt[6]);
  cy = abs(cnt[2] - cnt[5]);
  cz = abs(cnt[3] - cnt[4]);
  x = cnt[1] > cnt[6] ? 1 : 6;
  y = cnt[2] > cnt[5] ? 2 : 5;
  z = cnt[3] > cnt[4] ? 3 : 4;

  FOR(i, 0, cx + 1) {
    FOR(j, 0, cy + 1) {
      FOR(k, 0, cz + 1) {
        dp[i][j][k] += ((i * x + j * y + k * z) % 7 == 0);
        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
        dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
        dp[i][j][k + 1] = max(dp[i][j][k + 1], dp[i][j][k]);
      }
    }
  }
  cout << ans - dp[cx][cy][cz] + 1 << ENDL;

  return 0;
}