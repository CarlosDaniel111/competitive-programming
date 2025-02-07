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
      "AdventofCode/2024/Dia25/input.txt");

  string line;
  vector<string> grid;
  vector<vi> locks, gates;
  while (getline(file, line)) {
    if (SZ(line) == 0) {
      int n = SZ(grid), m = SZ(grid[0]);
      vi h;
      FOR(i, 0, m) {
        int cnt = 0;
        FOR(j, 0, n) { cnt += (grid[j][i] == '#'); }
        h.pb(cnt);
      }
      if (grid[0] == "#####") {
        locks.pb(h);
      } else
        gates.pb(h);
      grid.clear();
      continue;
    }
    grid.pb(line);
  }

  int n = SZ(grid), m = SZ(grid[0]);
  vi h;
  FOR(i, 0, m) {
    int cnt = 0;
    FOR(j, 0, n) { cnt += (grid[j][i] == '#'); }
    h.pb(cnt);
  }
  if (grid[0] == "#####") {
    locks.pb(h);
  } else
    gates.pb(h);

  auto check = [&](vi &lock, vi &gate) -> bool {
    FOR(i, 0, SZ(lock)) {
      if (lock[i] + gate[i] >= 8) return false;
    }
    return true;
  };
  ll ans = 0;
  for (auto &lock : locks) {
    for (auto &gate : gates) {
      ans += check(lock, gate);
    }
  }
  cout << ans << ENDL;

  return 0;
}