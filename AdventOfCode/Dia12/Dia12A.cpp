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

vector<string> grid;
vector<vi> vis;
int n, m;

bool isValid(int x, int y) { return (x >= 0 && x < n && y >= 0 && y < m); }
const int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1},
          dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
const int dx2[4] = {0, 0, 1, -1}, dy2[4] = {1, -1, 0, 0};
set<pi> per;
int perimetro, area;
void isPerimetro(int x, int y) {
  FOR(k, 0, 4) {
    int sigx = x + dx2[k], sigy = y + dy2[k];
    if (!isValid(sigx, sigy)) perimetro++;
    if (isValid(sigx, sigy) && grid[x][y] != grid[sigx][sigy]) perimetro++;
  }
}

void dfs(int x, int y, char c) {
  area++;
  isPerimetro(x, y);
  vis[x][y] = 1;
  FOR(k, 0, 4) {
    int sigx = x + dx2[k], sigy = y + dy2[k];
    if (isValid(sigx, sigy) && !vis[sigx][sigy] && grid[sigx][sigy] == c)
      dfs(sigx, sigy, c);
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ifstream file(
      "/Users/CarlosBeltran/Documents/ICPC/competitive-programming/"
      "AdventofCode/Dia12/input.txt");

  string line;
  while (getline(file, line)) {
    grid.pb(line);
  }
  n = SZ(grid), m = SZ(grid[0]);
  ll ans = 0;
  vis.assign(n, vi(m, 0));

  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (!vis[i][j]) {
        area = 0;
        perimetro = 0;
        dfs(i, j, grid[i][j]);
        ans += area * perimetro;
      }
    }
  }

  cout << ans << ENDL;

  return 0;
}