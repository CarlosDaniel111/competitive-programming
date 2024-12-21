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
      "AdventofCode/Dia8/input.txt");

  string line;
  vector<string> grid;
  while (getline(file, line)) {
    grid.pb(line);
  }
  map<char, vector<pi>> mp;
  set<pi> ans;
  int n = SZ(grid), m = SZ(grid[0]);
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (grid[i][j] != '.') {
        mp[grid[i][j]].pb({i, j});
        ans.insert({i, j});
      }
    }
  }

  for (auto &[c, pos] : mp) {
    FOR(i, 0, SZ(pos)) {
      FOR(j, 0, SZ(pos)) {
        if (i == j) continue;
        int distX = pos[i].first - pos[j].first;
        int distY = pos[i].second - pos[j].second;
        pi nw = pos[i];
        nw = {nw.first + distX, nw.second + distY};
        while (nw.first >= 0 && nw.first < n && nw.second >= 0 &&
               nw.second < m) {
          ans.insert(nw);
          nw = {nw.first + distX, nw.second + distY};
        }
      }
    }
  }

  cout << SZ(ans) << ENDL;

  return 0;
}