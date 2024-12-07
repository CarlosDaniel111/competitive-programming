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

  ifstream file(
      "/Users/CarlosBeltran/Documents/ICPC/competitive-programming/"
      "AdventofCode/Dia4/input.txt");

  string line;
  vector<string> grid;
  while (getline(file, line)) {
    grid.pb(line);
  }
  int n = SZ(grid), m = SZ(grid[0]);

  auto isValid = [&](int x, int y) -> bool {
    return (x >= 0 && x < n && y >= 0 && y < m);
  };
  int ans = 0;
  FOR(i, 0, SZ(grid)) {
    FOR(j, 0, SZ(grid[0])) {
      if (grid[i][j] == 'A') {
        if (isValid(i - 1, j - 1) && isValid(i - 1, j + 1) &&
            isValid(i + 1, j - 1) && isValid(i + 1, j + 1)) {
          if ((grid[i - 1][j - 1] == 'M' && grid[i + 1][j + 1] == 'S') or
              (grid[i - 1][j - 1] == 'S' && grid[i + 1][j + 1] == 'M')) {
            if ((grid[i - 1][j + 1] == 'M' && grid[i + 1][j - 1] == 'S') or
                (grid[i - 1][j + 1] == 'S' && grid[i + 1][j - 1] == 'M'))
              ans++;
          }
        }
      }
    }
  }
  cout << ans << ENDL;

  return 0;
}