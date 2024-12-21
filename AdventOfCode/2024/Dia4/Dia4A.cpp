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
      if (grid[i][j] == 'X') {
        // horizontal
        if (isValid(i, j + 1) && isValid(i, j + 2) && isValid(i, j + 3) &&
            grid[i][j + 1] == 'M' && grid[i][j + 2] == 'A' &&
            grid[i][j + 3] == 'S')
          ans++;
        if (isValid(i, j - 1) && isValid(i, j - 2) && isValid(i, j - 3) &&
            grid[i][j - 1] == 'M' && grid[i][j - 2] == 'A' &&
            grid[i][j - 3] == 'S')
          ans++;

        // Vertical
        if (isValid(i + 1, j) && isValid(i + 2, j) && isValid(i + 3, j) &&
            grid[i + 1][j] == 'M' && grid[i + 2][j] == 'A' &&
            grid[i + 3][j] == 'S')
          ans++;

        if (isValid(i - 1, j) && isValid(i - 2, j) && isValid(i - 3, j) &&
            grid[i - 1][j] == 'M' && grid[i - 2][j] == 'A' &&
            grid[i - 3][j] == 'S')
          ans++;

        // Diagonal
        if (isValid(i + 1, j + 1) && isValid(i + 2, j + 2) &&
            isValid(i + 3, j + 3) && grid[i + 1][j + 1] == 'M' &&
            grid[i + 2][j + 2] == 'A' && grid[i + 3][j + 3] == 'S')
          ans++;

        if (isValid(i - 1, j + 1) && isValid(i - 2, j + 2) &&
            isValid(i - 3, j + 3) && grid[i - 1][j + 1] == 'M' &&
            grid[i - 2][j + 2] == 'A' && grid[i - 3][j + 3] == 'S')
          ans++;

        if (isValid(i + 1, j - 1) && isValid(i + 2, j - 2) &&
            isValid(i + 3, j - 3) && grid[i + 1][j - 1] == 'M' &&
            grid[i + 2][j - 2] == 'A' && grid[i + 3][j - 3] == 'S')
          ans++;

        if (isValid(i - 1, j - 1) && isValid(i - 2, j - 2) &&
            isValid(i - 3, j - 3) && grid[i - 1][j - 1] == 'M' &&
            grid[i - 2][j - 2] == 'A' && grid[i - 3][j - 3] == 'S')
          ans++;
      }
    }
  }
  cout << ans << ENDL;

  return 0;
}