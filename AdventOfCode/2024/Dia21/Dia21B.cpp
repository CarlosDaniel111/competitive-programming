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
constexpr int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ifstream file(
      "/Users/CarlosBeltran/Documents/ICPC/competitive-programming/"
      "AdventofCode/Dia21/input.txt");

  string line;
  vector<string> grid;

  while (getline(file, line)) {
    grid.pb(line);
  }

  int n = SZ(grid), m = SZ(grid[0]);
  vector<vi> dist(n, vi(m, -1));
  pi start, end;
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (grid[i][j] == 'S') {
        start = {i, j};
      } else if (grid[i][j] == 'E') {
        end = {i, j};
      }
    }
  }

  auto isValid = [&](int x, int y) -> bool {
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' &&
            dist[x][y] == -1);
  };

  queue<pi> q;
  q.push(start);
  dist[start.first][start.second] = 0;
  while (SZ(q)) {
    auto [x, y] = q.front();
    q.pop();

    if (tie(x, y) == tie(end.first, end.second)) break;

    FOR(k, 0, 4) {
      int sigx = x + dx[k], sigy = y + dy[k];
      if (isValid(sigx, sigy)) {
        dist[sigx][sigy] = dist[x][y] + 1;
        q.push({sigx, sigy});
      }
    }
  }

  int ans = 0;
  FOR(x, 1, n - 1) {
    FOR(y, 1, m - 1) {
      if (grid[x][y] == '#') continue;
      FOR(movx, -21, 21) {
        FOR(movy, -21, 21) {
          int x2 = x + movx, y2 = y + movy;
          if (x2 < 0 or x2 >= n or y2 < 0 or y2 >= m or grid[x2][y2] == '#' or
              dist[x2][y2] == -1)
            continue;
          int d = abs(x2 - x) + abs(y2 - y);
          if (d <= 20) ans += ((dist[x2][y2] - dist[x][y] - d) >= 100);
        }
      }
    }
  }
  cout << ans << ENDL;

  return 0;
}