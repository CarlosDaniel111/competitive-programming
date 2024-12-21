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

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ifstream file(
      "/Users/CarlosBeltran/Documents/ICPC/competitive-programming/"
      "AdventofCode/Dia6/input.txt");

  string line;
  vector<string> grid;
  while (getline(file, line)) {
    grid.pb(line);
  }
  int n = SZ(grid), m = SZ(grid[0]);

  pi pos;
  int dir;
  FOR(i, 0, n) {
    FOR(j, 0, n) {
      if (grid[i][j] == '^') {
        pos = {i, j};
        dir = 0;
      } else if (grid[i][j] == '>') {
        pos = {i, j};
        dir = 1;
      } else if (grid[i][j] == 'v') {
        pos = {i, j};
        dir = 2;
      } else if (grid[i][j] == '<') {
        pos = {i, j};
        dir = 3;
      }
    }
  }

  auto isValid = [&](pi pos) -> bool {
    return (pos.first >= 0 && pos.first < n && pos.second >= 0 &&
            pos.second < m);
  };
  int ans = 0, cnt = 0;
  while (isValid(pos)) {
    if (grid[pos.first][pos.second] != 'X') {
      ans++;
      grid[pos.first][pos.second] = 'X';
    }
    pi sig = {pos.first + dx[dir], pos.second + dy[dir]};
    if (grid[sig.first][sig.second] == '#') dir = (dir + 1) % 4;
    sig = {pos.first + dx[dir], pos.second + dy[dir]};
    pos = sig;
  }
  cout << ans << ENDL;

  return 0;
}