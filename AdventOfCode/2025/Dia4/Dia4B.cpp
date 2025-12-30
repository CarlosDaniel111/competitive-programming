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

vector<string> split(string str, char pattern) {
  int posInit = 0;
  int posFound = 0;
  string splitted;
  vector<string> results;

  while (posFound >= 0) {
    posFound = str.find(pattern, posInit);
    splitted = str.substr(posInit, posFound - posInit);
    posInit = posFound + 1;
    results.push_back(splitted);
  }

  return results;
}
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ifstream file(
      "/Users/CarlosBeltran/Documents/ICPC/competitive-programming/"
      "AdventofCode/2025/Dia4/input.txt");

  string line;
  vector<string> grid;
  while (getline(file, line)) {
    grid.pb(line);
  }
  int n = SZ(grid), m = SZ(grid[0]);
  int ans = 0;
  while (true) {
    vector<string> grid2(n);
    int sumans = 0;
    FOR(i, 0, n) {
      FOR(j, 0, n) {
        grid2[i] += grid[i][j];
        if (grid[i][j] == '.') continue;
        int curr = 0;
        FOR(k, 0, 8) {
          int ii = i + dx[k], jj = j + dy[k];
          if (ii >= 0 && ii < n && jj >= 0 && jj < m && grid[ii][jj] == '@')
            curr++;
        }
        sumans += (curr < 4);
        if (curr < 4) {
          grid2[i][j] = '.';
        }
      }
    }
    if (sumans == 0) break;
    ans += sumans;
    swap(grid, grid2);
  }

  cout << ans << ENDL;

  return 0;
}