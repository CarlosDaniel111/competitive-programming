#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

vector<string> split(string str, char pattern) {
  ll posInit = 0;
  ll posFound = 0;
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

constexpr ll INF = 5e15;
constexpr ll dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ifstream file(
      "/Users/CarlosBeltran/Documents/ICPC/competitive-programming/"
      "AdventofCode/Dia16/input.txt");

  string line;
  vector<string> grid;
  while (getline(file, line)) {
    grid.pb(line);
  }

  ll n = SZ(grid), m = SZ(grid[0]);
  vector<vector<vi>> dist(n, vector<vi>(m, vi(4, INF)));
  pi pos, end;
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (grid[i][j] == 'S') {
        pos = {i, j};
      }
      if (grid[i][j] == 'E') {
        end = {i, j};
      }
    }
  }
  dist[pos.first][pos.second][3] = 0;
  priority_queue<tuple<ll, ll, ll, ll, vector<pi>>> pq;
  pq.push({0, pos.first, pos.second, 3, {}});
  set<pi> usado[4];
  while (SZ(pq)) {
    auto [di, x, y, dir, path] = pq.top();
    pq.pop();
    di *= -1;
    if (di > dist[x][y][dir]) continue;
    path.pb({x, y});
    if (x == end.first && y == end.second) {
      for (auto p : path) {
        usado[dir].insert(p);
      }
    }
    FOR(k, 0, 4) {
      ll newDi = di + 1 + 1000 * (k != dir);
      ll sigX = x + dx[k], sigY = y + dy[k];
      if (grid[sigX][sigY] == '#') continue;
      if (newDi <= dist[sigX][sigY][k]) {
        dist[sigX][sigY][k] = newDi;
        pq.push({-newDi, sigX, sigY, k, path});
      }
    }
  }

  ll ans = INF;
  FOR(k, 0, 4) { ans = min(ans, dist[end.first][end.second][k]); }

  set<pi> camino;
  FOR(k, 0, 4) {
    if (dist[end.first][end.second][k] == ans) {
      for (auto p : usado[k]) {
        grid[p.first][p.second] = 'O';
        camino.insert(p);
      }
    }
  }
  FOR(i, 0, n) {
    FOR(j, 0, m) { cout << grid[i][j]; }
    cout << ENDL;
  }

  cout << SZ(camino) << ENDL;

  return 0;
}