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
      "AdventofCode/2024/Dia24/input.txt");

  string line;
  bool f = false;
  map<string, int> mp;
  vector<tuple<string, string, string, string>> faltan;
  while (getline(file, line)) {
    if (SZ(line) == 0) {
      f = true;
      continue;
    }
    if (f) {
      vector<string> input = split(line, ' ');
      faltan.pb({input[0], input[1], input[2], input[4]});
      continue;
    }
    string var = split(line, ' ')[0];
    var = var.substr(0, SZ(var) - 1);
    int val = stoi(split(line, ' ')[1]);
    mp[var] = val;
  }

  cout << SZ(faltan) << ENDL;

  while (SZ(faltan)) {
    vector<tuple<string, string, string, string>> sig;
    for (auto &[v1, op, v2, res] : faltan) {
      if (mp.count(v1) && mp.count(v2)) {
        if (op[0] == 'A') {
          mp[res] = mp[v1] & mp[v2];
        } else if (op[0] == 'O') {
          mp[res] = mp[v1] | mp[v2];
        } else {
          mp[res] = mp[v1] ^ mp[v2];
        }
      } else {
        sig.pb({v1, op, v2, res});
      }
    }
    faltan = sig;
  }
  int cnt = 0;
  ll ans = 0;
  for (auto &[var, val] : mp) {
    if (var[0] == 'z') {
      if (val) ans |= (1ll << cnt);
      cnt++;
    }
  }
  cout << ans << ENDL;

  return 0;
}