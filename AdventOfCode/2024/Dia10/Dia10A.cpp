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
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

vector<string> grid;
set<pi> nueves;
int solve(int posX, int posY, int curr) {
  if (curr == 9) nueves.insert({posX, posY});
  int ans = 0;

  FOR(k, 0, 4) {
    int sigX = posX + dx[k], sigY = posY + dy[k];
    if (sigX >= 0 && sigX < SZ(grid) && sigY >= 0 && sigY < SZ(grid[0]) &&
        ((grid[sigX][sigY] - '0') == curr + 1))
      solve(sigX, sigY, curr + 1);
  }
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ifstream file(
      "/Users/CarlosBeltran/Documents/ICPC/competitive-programming/"
      "AdventofCode/Dia10/input.txt");

  string line;

  while (getline(file, line)) {
    grid.pb(line);
  }
  ll ans = 0;
  FOR(i, 0, SZ(grid)) {
    FOR(j, 0, SZ(grid[0])) {
      if (grid[i][j] == '0') {
        nueves.clear();
        solve(i, j, 0);
        ans += SZ(nueves);
      }
    }
  }
  cout << ans << ENDL;

  return 0;
}