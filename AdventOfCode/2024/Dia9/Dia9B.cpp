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
      "AdventofCode/Dia9/input.txt");

  string line;
  while (getline(file, line)) {
    vector<int> ids;
    int currID = 0;
    set<int> disp;
    FOR(i, 0, SZ(line)) {
      FOR(_, 0, line[i] - '0') {
        if (i & 1) {
          ids.pb(-1);
          disp.insert(SZ(ids) - 1);
        } else {
          ids.pb(currID);
        }
      }
      if (i % 2 == 0) currID++;
    }

    while (SZ(disp)) {
      bool entro = false;
      while (ids.back() == -1) {
        entro = true;
        disp.erase(SZ(ids) - 1);
        ids.pop_back();
      }
      if (entro) continue;
      auto it = disp.begin();
      ids[*it] = ids.back();
      disp.erase(it);
      ids.pop_back();
    }
    ll ans = 0;
    FOR(i, 0, SZ(ids)) { ans += i * ids[i]; }
    cout << ans << ENDL;
  }

  return 0;
}