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

const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int area;
set<tuple<int, int, int, int>> perimetro;

void dfs(int x, int y, char c) {
  if (vis[x][y]) return;
  vis[x][y] = 1;
  area++;
  FOR(k, 0, 4) {
    int sigx = x + dx[k], sigy = y + dy[k];
    if (isValid(sigx, sigy) && grid[sigx][sigy] == c)
      dfs(sigx, sigy, c);
    else
      perimetro.insert({x, y, sigx, sigy});
  }
}

set<tuple<int, int, int, int>> visLados;

void dfsLados(tuple<int, int, int, int> lado) {
  if (visLados.count(lado) or !perimetro.count(lado)) return;
  visLados.insert(lado);
  auto [x, y, x2, y2] = lado;
  if (x == x2) {
    dfsLados({x - 1, y, x2 - 1, y2});
    dfsLados({x + 1, y, x2 + 1, y2});
  } else {
    dfsLados({x, y - 1, x2, y2 - 1});
    dfsLados({x, y + 1, x2, y2 + 1});
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
        perimetro.clear();
        dfs(i, j, grid[i][j]);
        int lados = 0;
        for (auto lado : perimetro) {
          if (visLados.count(lado)) continue;
          lados++;
          dfsLados(lado);
        }
        ans += area * lados;
      }
    }
  }

  cout << ans << ENDL;

  return 0;
}