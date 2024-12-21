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
      "AdventofCode/Dia15/input.txt");

  string line;
  bool isGrid = true;
  vector<string> grid;
  vector<string> moves;
  while (getline(file, line)) {
    if (SZ(line) == 0) {
      isGrid = false;
      continue;
    }
    if (isGrid) {
      grid.pb(line);
    } else {
      moves.pb(line);
    }
  }
  int n = SZ(grid), m = SZ(grid[0]);
  pi pos;
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (grid[i][j] == '@') {
        pos = {i, j};
        break;
      }
    }
  }

  auto mover = [&](int movX, int movY) -> void {
    pi curr = pos;
    int cnt = 0;
    while (true) {
      if (grid[curr.first][curr.second] == '.') {
        FOR(i, 0, cnt) {
          pi ant = {curr.first - movX, curr.second - movY};
          swap(grid[curr.first][curr.second], grid[ant.first][ant.second]);
          curr = ant;
        }
        pos = {pos.first + movX, pos.second + movY};
        return;
      }
      if (grid[curr.first][curr.second] == '#') return;
      curr = {curr.first + movX, curr.second + movY};
      cnt++;
    }
  };

  for (auto move : moves) {
    for (auto c : move) {
      if (c == 'v') {
        mover(1, 0);
      } else if (c == '>') {
        mover(0, 1);
      } else if (c == '<') {
        mover(0, -1);
      } else {
        mover(-1, 0);
      }
    }
  }

  ll ans = 0;
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (grid[i][j] == 'O') {
        ans += 100 * i + j;
      }
    }
  }
  cout << ans << ENDL;

  return 0;
}