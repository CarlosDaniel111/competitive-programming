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

  string linea;
  int ans = 0;
  int cnt = 0;
  while (getline(cin, linea)) {
    vector<string> lineaSplit = split(linea, ' ');
    vi a;
    for (auto x : lineaSplit) a.pb(stoi(x));

    auto check = [&](bool up) {
      FOR(i, 0, SZ(a) - 1) {
        if (a[i] - a[i + 1] == 0) return false;
        int diff = a[i + 1] - a[i];
        if (abs(diff) > 3) return false;
        if (diff <= 3 && diff >= 1 && !up) return false;
        if (diff >= -3 && diff <= -1 && up) return false;
      }
      return true;
    };
    ans += check(a[0] < a[1]);
    cnt++;
  }
  cout << ans << ENDL;

  return 0;
}