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

int cuad[4005][4005];
int romb[8005][8005];

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  FOR(i, 0, n) {
    int x, y, r;
    char op;
    cin >> op;
    cin >> x >> y >> r;
    r /= 2;
    if (op == 'A') {
      cuad[2000 + x - r][2000 + y - r]++;
      cuad[2000 + x - r][2000 + y + r]--;
      cuad[2000 + x + r][2000 + y - r]--;
      cuad[2000 + x + r][2000 + y + r]++;
    } else {
      romb[4000 + x - y + r][4000 + x + y - r]++;
      romb[4000 + x - y - r][4000 + x + y - r]--;
      romb[4000 + x - y + r][4000 + x + y + r]--;
      romb[4000 + x - y - r][4000 + x + y + r]++;
    }
  }

  FOR(i, 1, 4001) {
    FOR(j, 1, 4001) {
      cuad[i][j] += cuad[i][j - 1] + cuad[i - 1][j] - cuad[i - 1][j - 1];
    }
  }

  FOR(i, 1, 8001) {
    FOR(j, 1, 8001) {
      romb[i][j] += romb[i][j - 1] + romb[i - 1][j] - romb[i - 1][j - 1];
    }
  }
  double ans = 0.0;
  FOR(i, 1, 4001) {
    FOR(j, 1, 4001) {
      if (cuad[i][j])
        ans++;
      else {
        if (romb[4000 + i - j][i + j]) ans += 0.25;
        if (romb[4000 + i - j][i + j + 1]) ans += 0.25;
        if (romb[4000 + i - j - 1][i + j]) ans += 0.25;
        if (romb[4000 + i - j - 1][i + j + 1]) ans += 0.25;
      }
    }
  }
  cout << setprecision(2) << fixed;
  cout << ans << ENDL;

  return 0;
}