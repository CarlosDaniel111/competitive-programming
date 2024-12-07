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
      "AdventofCode/Dia5/input.txt");

  string line;
  bool ok = true;
  map<int, vi> mp, mp2;
  int ans = 0;
  while (getline(file, line)) {
    if (SZ(line) == 0) {
      ok = false;
      continue;
    }
    if (ok) {
      vector<string> a = split(line, '|');
      int n1 = stoi(a[0]), n2 = stoi(a[1]);
      mp[n2].pb(n1);
      continue;
    }
    vector<string> a = split(line, ',');
    set<int> importan;
    for (auto s : a) {
      importan.insert(stoi(s));
    }

    set<int> vis;
    bool bien = true;
    for (auto s : a) {
      bool ok1 = 1;
      int num = stoi(s);
      for (auto x : mp[num]) {
        if (!importan.count(x)) continue;
        if (!vis.count(x)) {
          ok1 = false;
          break;
        }
      }
      if (!ok1) {
        bien = false;
        break;
      }
      vis.insert(num);
    }
    if (bien) {
      ans += stoi(a[SZ(a) / 2]);
    }
  }
  cout << ans << ENDL;

  return 0;
}