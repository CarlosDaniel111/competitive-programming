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
    g[u].pb(v);
    g[v].pb(u);
    g2[u].insert(v);
    g2[v].insert(u);
    nodos.insert(u);
    nodos.insert(v);
  }

  set<tuple<string, string, string>> tripletas;
  for (auto u : nodos) {
    for (auto v : g2[u]) {
      for (auto w : g2[u]) {
        if (u == w or u == v or v == w) continue;
        if (g2[v].count(w)) {
          vector<string> aux;
          aux.pb(u);
          aux.pb(v);
          aux.pb(w);
          sort(ALL(aux));
          tripletas.insert({aux[0], aux[1], aux[2]});
        }
      }
    }
  }
  cout << SZ(nodos) << ENDL;
  int ans = 0;
  for (auto [u, v, w] : tripletas) {
    // cout << u << " " << v << " " << w << ENDL;
    if (u[0] == 't' or v[0] == 't' or w[0] == 't') ans++;
  }
  cout << ans << ENDL;

  return 0;
}