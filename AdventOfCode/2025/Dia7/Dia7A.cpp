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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ifstream file(
      "/Users/CarlosBeltran/Documents/ICPC/competitive-programming/"
      "AdventofCode/2025/Dia7/input.txt");

  string line;
  vector<string> grid;
  while (getline(file, line)) {
    grid.pb(line);
  }
  int n = SZ(grid), m = SZ(grid[0]);
  queue<pi> q;
  vector<vi> vis(n, vi(m, 0));
  FOR(i, 0, n) FOR(j, 0, m) if (grid[i][j] == 'S') {
    q.push({i, j});
    vis[i][j] = 1;
    break;
  }
  int ans = 0;
  while (SZ(q)) {
    auto [x, y] = q.front();
    q.pop();
    if (x == n - 1) continue;
    if (grid[x + 1][y] == '^') {
      ans++;
      if (y != 0 && !vis[x + 1][y - 1]) {
        q.push({x + 1, y - 1});
        vis[x + 1][y - 1] = 1;
      }
      if (y != m - 1 && !vis[x + 1][y + 1]) {
        q.push({x + 1, y + 1});
        vis[x + 1][y + 1] = 1;
      }
    } else if (x != n - 1 && !vis[x + 1][y]) {
      q.push({x + 1, y});
      vis[x + 1][y] = 1;
    }
  }
  cout << ans << ENDL;

  return 0;
}