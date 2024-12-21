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
  vector<string> gridOld;
  vector<string> moves;
  while (getline(file, line)) {
    if (SZ(line) == 0) {
      isGrid = false;
      continue;
    }
    if (isGrid) {
      gridOld.pb(line);
    } else {
      moves.pb(line);
    }
  }
  vector<vector<char>> grid(SZ(gridOld));
  FOR(i, 0, SZ(gridOld)) {
    for (auto c : gridOld[i]) {
      if (c == '#') {
        grid[i].pb('#');
        grid[i].pb('#');
      } else if (c == 'O') {
        grid[i].pb('[');
        grid[i].pb(']');
      } else if (c == '.') {
        grid[i].pb('.');
        grid[i].pb('.');
      } else {
        grid[i].pb('@');
        grid[i].pb('.');
      }
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

  int cnt;

  auto checarHor = [&](pi curr, char mov) -> pair<bool, pi> {
    if (mov == '<') {
      while (true) {
        if (grid[curr.first][curr.second] == '.') {
          return {true, curr};
        }
        if (grid[curr.first][curr.second] == '#') {
          return {false, curr};
        }
        cnt++;
        curr = {curr.first, curr.second - 1};
      }
    }

    if (mov == '>') {
      while (true) {
        if (grid[curr.first][curr.second] == '.') {
          return {true, curr};
        }
        if (grid[curr.first][curr.second] == '#') {
          return {false, curr};
        }
        cnt++;
        curr = {curr.first, curr.second + 1};
      }
    }
    return {true, curr};
  };

  int l, r, currX;
  vector<pi> lr;
  auto checarVer = [&](auto self, pi curr, int movX, int d) -> bool {
    if (d == 0) {
      lr.pb({curr.second, curr.second + 1});
    } else {
      if (SZ(lr) == d) lr.pb({1e9, 0});
      lr[d] = {min(curr.second, lr[d].first),
               max(curr.second + 1, lr[d].second)};
    }
    pi sig = {curr.first + movX, curr.second};
    if (grid[sig.first][sig.second] == '[') {
      cnt++;
      return self(self, sig, movX, d + 1);
    }
    if (grid[sig.first][sig.second] == ']' &&
        grid[sig.first][sig.second + 1] == '[') {
      cnt++;
      return (self(self, {sig.first, sig.second - 1}, movX, d + 1) &&
              self(self, {sig.first, sig.second + 1}, movX, d + 1));
    }
    if (grid[sig.first][sig.second] == ']' &&
        grid[sig.first][sig.second + 1] == '.') {
      cnt++;
      return (self(self, {sig.first, sig.second - 1}, movX, d + 1));
    }
    if (grid[sig.first][sig.second] == '.' &&
        grid[sig.first][sig.second + 1] == '[') {
      cnt++;
      return (self(self, {sig.first, sig.second + 1}, movX, d + 1));
    }

    if (grid[sig.first][sig.second] == '.' &&
        grid[sig.first][sig.second + 1] == '.') {
      if (movX == 1) {
        currX = max(currX, sig.first);
      } else {
        currX = min(currX, sig.first);
      }
      return true;
    }
    return false;
  };

  auto mover = [&](char mov) -> void {
    if (mov == '<') {
      cnt = 0;
      auto [p, curr] = checarHor(pos, mov);
      if (!p) return;
      FOR(i, 0, cnt) {
        pi ant = {curr.first, curr.second + 1};
        swap(grid[curr.first][curr.second], grid[ant.first][ant.second]);
        curr = ant;
      }
      pos = {pos.first, pos.second - 1};
      return;
    }

    if (mov == '>') {
      cnt = 0;
      auto [p, curr] = checarHor(pos, mov);
      if (!p) return;
      FOR(i, 0, cnt) {
        pi ant = {curr.first, curr.second - 1};
        swap(grid[curr.first][curr.second], grid[ant.first][ant.second]);
        curr = ant;
      }
      pos = {pos.first, pos.second + 1};
      return;
    }

    if (mov == 'v') {
      if (grid[pos.first + 1][pos.second] == '.') {
        swap(grid[pos.first][pos.second], grid[pos.first + 1][pos.second]);
        pos = {pos.first + 1, pos.second};
        return;
      }
      if (grid[pos.first + 1][pos.second] == '#') {
        return;
      }
      if (grid[pos.first + 1][pos.second] == '[') {
        currX = pos.first;
        lr.clear();
        if (!checarVer(checarVer, {pos.first + 1, pos.second}, 1, 0)) return;
      }
      if (grid[pos.first + 1][pos.second] == ']') {
        currX = pos.first;
        lr.clear();
        if (!checarVer(checarVer, {pos.first + 1, pos.second - 1}, 1, 0))
          return;
      }
      ROF(i, SZ(lr), 0) {
        FOR(j, lr[i].first, lr[i].second + 1) {
          swap(grid[currX][j], grid[currX - 1][j]);
        }
        currX--;
      }
      swap(grid[pos.first][pos.second], grid[pos.first + 1][pos.second]);
      pos = {pos.first + 1, pos.second};
      return;
    }

    if (mov == '^') {
      if (grid[pos.first - 1][pos.second] == '.') {
        swap(grid[pos.first][pos.second], grid[pos.first - 1][pos.second]);
        pos = {pos.first - 1, pos.second};
        return;
      }
      if (grid[pos.first - 1][pos.second] == '#') {
        return;
      }
      if (grid[pos.first - 1][pos.second] == '[') {
        currX = pos.first;
        lr.clear();
        if (!checarVer(checarVer, {pos.first - 1, pos.second}, -1, 0)) return;
      }
      if (grid[pos.first - 1][pos.second] == ']') {
        currX = pos.first;
        lr.clear();
        if (!checarVer(checarVer, {pos.first - 1, pos.second - 1}, -1, 0))
          return;
      }
      ROF(i, SZ(lr), 0) {
        FOR(j, lr[i].first, lr[i].second + 1) {
          swap(grid[currX][j], grid[currX + 1][j]);
        }
        currX++;
      }
      swap(grid[pos.first][pos.second], grid[pos.first - 1][pos.second]);
      pos = {pos.first - 1, pos.second};
      return;
    }
  };

  for (auto move : moves) {
    for (auto c : move) {
      mover(c);
    }
  }

  ll ans = 0;
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (grid[i][j] == '[') {
        ans += 100ll * i + j;
      }
    }
  }
  cout << ans << ENDL;

  return 0;
}