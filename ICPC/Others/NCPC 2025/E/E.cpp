#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ENDL '\n'

using ll = long long;

int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

void print(vector<vector<char>> ans) {
  int n = ans.size(), m = ans[0].size();
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (ans[i][j] == '.' or ans[i][j] == 'C')
        cout << 'B';
      else
        cout << ans[i][j];
    }
    cout << '\n';
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  int m = 2 * n - 1;
  vector<string> grid(n);
  FOR(i, 0, n) cin >> grid[i];
  int c = 0;
  FOR(i, 0, n) FOR(j, 0, m) if (grid[i][j] == 'C') c++;
  if (c & 1) {
    cout << "impossible" << '\n';
    return 0;
  }
  vector<vector<char>> ans(n, vector<char>(m));
  vector<vector<int>> vis(n, vector<int>(m, 0));
  auto isValid = [&](int x, int y) -> bool {
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' &&
            !vis[x][y]);
  };

  queue<pair<int, int>> q;
  FOR(i, 0, n) FOR(j, 0, m) ans[i][j] = grid[i][j];
  int c1 = 0;
  FOR(i, 0, n) {
    q.push({i, n - 1 + i});
    if (grid[i][n - 1 + i] == 'C') c1++;
    vis[i][n - 1 + i] = 1;
    ans[i][n - 1 + i] = 'A';
    if (i != n - 1) {
      q.push({i + 1, n - 1 + i});
      ans[i + 1][n - 1 + i] = 'A';
      vis[i + 1][n - 1 + i] = 1;
      if (grid[i + 1][n - 1 + i] == 'C') c1++;
    }
  }
  if (c1 == c / 2) {
    print(ans);
    return 0;
  } else if (c1 < c / 2) {
    c1 = 0;
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      ans[x][y] = 'A';
      c1 += grid[x][y] == 'C';
      if (c1 == c / 2) break;
      FOR(k, 0, 4) {
        int sx = x + dx[k], sy = y + dy[k];
        if (isValid(sx, sy)) {
          vis[sx][sy] = 1;
          q.push({sx, sy});
        }
      }
    }
    if (c1 == c / 2) {
      print(ans);
      return 0;
    }
  }

  while (q.size()) q.pop();
  vis.assign(n, vector<int>(m, 0));
  FOR(i, 0, n) FOR(j, 0, m) ans[i][j] = grid[i][j];
  c1 = 0;
  FOR(i, 0, n) {
    q.push({i, n - 1 - i});
    if (grid[i][n - 1 - i] == 'C') c1++;
    ans[i][n - 1 - i] = 'A';
    vis[i][n - 1 - i] = 1;
    if (i != n - 1) {
      q.push({i + 1, n - 1 - i});
      vis[i + 1][n - 1 - i] = 1;
      ans[i + 1][n - 1 - i] = 'A';
      if (grid[i + 1][n - 1 - i] == 'C') c1++;
    }
  }

  if (c1 == c / 2) {
    print(ans);
    return 0;
  } else if (c1 < c / 2) {
    c1 = 0;
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      ans[x][y] = 'A';
      c1 += grid[x][y] == 'C';
      if (c1 == c / 2) break;
      FOR(k, 0, 4) {
        int sx = x + dx[k], sy = y + dy[k];
        if (isValid(sx, sy)) {
          vis[sx][sy] = 1;
          q.push({sx, sy});
        }
      }
    }
    if (c1 == c / 2) {
      print(ans);
      return 0;
    }
  }

  while (q.size()) q.pop();
  vis.assign(n, vector<int>(m, 0));
  FOR(i, 0, n) FOR(j, 0, m) ans[i][j] = grid[i][j];
  c1 = 0;
  FOR(i, 0, m / 2) {
    q.push({n - 1, i});
    if (grid[n - 1][i] == 'C') c1++;
    ans[n - 1][i] = 'A';
    vis[n - 1][i] = 1;

    q.push({n - 1, m - i - 1});
    if (grid[n - 1][m - i - 1] == 'C') c1++;
    ans[n - 1][m - i - 1] = 'A';
    vis[n - 1][m - i - 1] = 1;
  }
  q.push({n - 1, m / 2});
  if (grid[n - 1][m / 2] == 'C') c1++;
  ans[n - 1][m / 2] = 'A';
  vis[n - 1][m / 2] = 1;

  if (c1 == c / 2) {
    print(ans);
    return 0;
  } else if (c1 < c / 2) {
    c1 = 0;
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      ans[x][y] = 'A';
      c1 += grid[x][y] == 'C';
      if (c1 == c / 2) break;
      FOR(k, 0, 4) {
        int sx = x + dx[k], sy = y + dy[k];
        if (isValid(sx, sy)) {
          vis[sx][sy] = 1;
          q.push({sx, sy});
        }
      }
    }
    if (c1 == c / 2) {
      print(ans);
      return 0;
    }
  }
  cout << "impossible" << '\n';
  return 0;
}