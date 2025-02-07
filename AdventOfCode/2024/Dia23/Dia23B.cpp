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
      "AdventofCode/2024/Dia23/input.txt");

  string line;
  map<string, vector<string>> g;
  map<string, set<string>> g2;
  set<string> nodos;
  while (getline(file, line)) {
    string u = split(line, '-')[0];
    string v = split(line, '-')[1];
    g2[u].insert(v);
    g2[v].insert(u);
    nodos.insert(u);
    nodos.insert(v);
  }

  vector<string> all;
  for (auto s : nodos) all.pb(s);
  set<string> ans;
  FOR(_, 0, 1000) {
    shuffle(ALL(all), mt19937(time(0)));
    set<string> clique;
    for (auto u : all) {
      bool ok = true;
      for (auto v : clique) {
        if (!g2[v].count(u)) {
          ok = false;
          break;
        }
      }
      if (ok) {
        clique.insert(u);
      }
    }
    if (SZ(clique) > SZ(ans)) {
      ans = clique;
    }
  }
  for (auto s : ans) {
    cout << s << ",";
  }

  return 0;
}