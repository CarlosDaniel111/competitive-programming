#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

struct Destino {
  int x, y, dir;
} dest[510][510][4];

char grid[510][510];
int n, m;

// Derecha, Izquierda, Abajo, Arriba
constexpr int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
bool vis[510][510][4];

Destino dfs(int x, int y, int dir) {
  if (vis[x][y][dir]) return dest[x][y][dir];

  if (x == 0) return dfs(x + 1, y, 2);
  if (x == n + 1) return dfs(x - 1, y, 3);
  if (y == 0) return dfs(x, y + 1, 0);
  if (y == m + 1) return dfs(x, y - 1, 1);

  vis[x][y][dir] = 1;
  if (grid[x][y] == '#' || grid[x][y] == 'V' || grid[x][y] == 'H') {
    dest[x][y][dir] = {x, y, dir};
    return dest[x][y][dir];
  }

  if (grid[x][y] == '/') {
    if (dir == 0) return dest[x][y][dir] = dfs(x - 1, y, 3);
    if (dir == 1) return dest[x][y][dir] = dfs(x + 1, y, 2);
    if (dir == 2) return dest[x][y][dir] = dfs(x, y - 1, 1);
    if (dir == 3) return dest[x][y][dir] = dfs(x, y + 1, 0);
  }
  if (grid[x][y] == '\\') {
    if (dir == 0) return dest[x][y][dir] = dfs(x + 1, y, 2);
    if (dir == 1) return dest[x][y][dir] = dfs(x - 1, y, 3);
    if (dir == 2) return dest[x][y][dir] = dfs(x, y + 1, 0);
    if (dir == 3) return dest[x][y][dir] = dfs(x, y - 1, 1);
  }
  return dest[x][y][dir] = dfs(x + dx[dir], y + dy[dir], dir);
}

// f:0 H, f:1 V
bool vis2[510][510];
int tmpDir[510][510];
vector<pi> tmpCambios;
int dfs2(int x, int y, int f) {
  vis2[x][y] = 1;
  if (tmpDir[x][y] != -1) {
    if (tmpDir[x][y] != f) return 1e6;
    return 0;
  }
  if (grid[x][y] == '#') return 1e6;

  tmpDir[x][y] = f;
  tmpCambios.pb({x, y});

  int res = 0;
  if ((grid[x][y] == 'H' && f == 1) || (grid[x][y] == 'V' && f == 0)) res++;

  FOR(k, 0, 4) {
    int sx = x + dx[k], sy = y + dy[k];
    Destino v = dest[sx][sy][k];
    if (k / 2 == f)
      res += dfs2(v.x, v.y, v.dir / 2);
    else {
      if (grid[v.x][v.y] == '#')
        continue;
      else
        res += dfs2(v.x, v.y, 1 - v.dir / 2);
    }
  }
  return res;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m;
  FOR(i, 1, n + 1) {
    FOR(j, 1, m + 1)
    cin >> grid[i][j];
  }

  FOR(i, 1, n + 1) {
    FOR(j, 1, m + 1) {
      FOR(dir, 0, 4) {
        if (!vis[i][j][dir]) dest[i][j][dir] = dfs(i, j, dir);
      }
    }
  }

  FOR(i, 1, n + 1) {
    dest[i][0][1] = dest[i][1][0];
    dest[i][m + 1][0] = dest[i][m][1];
  }
  FOR(i, 1, m + 1) {
    dest[0][i][3] = dest[1][i][2];
    dest[n + 1][i][2] = dest[n][i][3];
  }

  memset(tmpDir, -1, sizeof(tmpDir));

  int ans = 0;

  FOR(i, 1, n + 1) {
    FOR(j, 1, m + 1) {
      if ((grid[i][j] == 'V' || grid[i][j] == 'H') && !vis2[i][j]) {
        int opc1 = dfs2(i, j, 0);
        for (auto x : tmpCambios)
          tmpDir[x.first][x.second] = -1;
        int opc2 = dfs2(i, j, 1);
        ans += min(opc1, opc2);
        if (ans >= 1e6) {
          cout << -1 << ENDL;
          return 0;
        }
      }
    }
  }

  cout << ans << ENDL;

  return 0;
}