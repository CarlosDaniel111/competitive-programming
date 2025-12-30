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
      "AdventofCode/2025/Dia11/input.txt");

  string line;
  map<string, vector<string>> g;
  while (getline(file, line)) {
    vector<string> input = split(line, ' ');
    string from = input[0].substr(0, SZ(input[0]) - 1);
    FOR(i, 1, SZ(input)) { g[from].pb(input[i]); }
  }

  map<string, long long> cnt[2][2];

  auto solve = [&](auto self, string u, bool vis1, bool vis2) -> long long {
    if (u == "out" && vis1 && vis2) return 1;
    if (cnt[vis1][vis2].count(u)) return cnt[vis1][vis2][u];
    for (auto v : g[u])
      cnt[vis1][vis2][u] +=
          self(self, v, vis1 | (v == "dac"), vis2 | (v == "fft"));
    return cnt[vis1][vis2][u];
  };
  cout << solve(solve, "svr", 0, 0) << ENDL;

  return 0;
}