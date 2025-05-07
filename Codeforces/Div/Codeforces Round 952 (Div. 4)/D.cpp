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
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  FOR(i, 0, n) { cin >> grid[i]; }
  int r = 0;
  FOR(i, 0, n) {
    int cnt = 0;
    FOR(j, 0, m) { cnt += grid[i][j] == '#'; }
    r = max(r, cnt);
  }
  r /= 2;

  auto isValid = [&](int x, int y) -> bool {
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '#');
  };

  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (grid[i][j] == '#') {
        if (isValid(i - r, j) && isValid(i + r, j) && isValid(i, j - r) &&
            isValid(i, j + r)) {
          cout << i + 1 << " " << j + 1 << ENDL;
          return;
        }
      }
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}