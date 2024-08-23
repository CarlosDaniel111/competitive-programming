#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

constexpr int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

vector<string> grid;
vector<vector<bool>> visited;
int w, h;

bool isValid(int x, int y) {
  return (x >= 0 && x < h && y >= 0 && y < w && grid[x][y] == '#' && !visited[x][y]);
}

void dfs(int x, int y) {
  visited[x][y] = true;
  FOR(k, 0, 8) {
    if (isValid(x + dx[k], y + dy[k]))
      dfs(x + dx[k], y + dy[k]);
  }
}

bool isNoise(int x, int y) {
  FOR(k, 0, 8) {
    if (grid[x + dx[k]][y + dy[k]] == '#') return false;
  }
  return true;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> w >> h;
  grid.resize(h);
  visited.assign(h, vector<bool>(w, 0));
  FOR(i, 0, h) {
    cin >> grid[i];
  }

  dfs(0, 0);

  // Busca los noise
  FOR(i, 0, h) {
    FOR(j, 0, w) {
      if (!visited[i][j] && grid[i][j] == '#' && isNoise(i, j))
        visited[i][j] = true;
    }
  }

  int A = 0, B = 0, C = 0;

  FOR(i, 0, h) {
    FOR(j, 0, w) {
      if (!visited[i][j] && grid[i][j] == '#') {
        // Contar ancho
        int jj = j;
        while (grid[i][jj] == '#') jj++;
        int ancho = jj - j;

        // contar altura
        int ii = i;
        while (grid[ii][j] == '#') ii++;
        int altura = ii - i;

        dfs(i, j);
        // cout << "Encontrado " << ancho << " " << altura << ENDL;

        // Checa si es A
        if (grid[ii - 1][j + (ancho / 2)] == '.') {
          A++;
        } else if (grid[i + (altura / 2)][jj - 1] == '.') {
          C++;
        } else {
          B++;
        }
      }
    }
  }

  cout << A << " " << B << " " << C << ENDL;

  return 0;
}