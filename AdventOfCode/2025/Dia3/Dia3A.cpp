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
      "AdventofCode/2025/Dia3/input.txt");

  string line;
  ll ans = 0;
  while (getline(file, line)) {
    int n = SZ(line);
    int mxi = 0;
    FOR(i, 0, n - 1) {
      if (line[i] > line[mxi]) {
        mxi = i;
      }
    }
    int mxi2 = mxi + 1;
    FOR(i, mxi + 1, n) {
      if (line[i] > line[mxi2]) {
        mxi2 = i;
      }
    }
    string num = "";
    num += line[mxi];
    num += line[mxi2];
    ans += stoi(num);
  }
  cout << ans << ENDL;

  return 0;
}