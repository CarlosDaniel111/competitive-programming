#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

vector<string> split(string str, char pattern) {
  ll posInit = 0;
  ll posFound = 0;
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
      "AdventofCode/Dia13/input.txt");

  string line;
  ll cnt = 0;
  ll x1, y1, x2, y2, px, py;
  ll ans = 0;
  while (getline(file, line)) {
    if (cnt == 3) {
      cnt = 0;
      ll best = 1e9;
      FOR(i, 0, 101) {
        FOR(j, 0, 101) {
          if (x1 * i + x2 * j == px && y1 * i + y2 * j == py) {
            best = min(best, i * 3 + j);
          }
        }
      }
      if (best != 1e9) ans += best;
      continue;
    }
    if (cnt == 0) {
      stringstream ss(line);
      string s;
      while (ss >> s) {
        if (s[0] == 'X') {
          x1 = stoll(s.substr(2, SZ(s) - 3));
        } else if (s[0] == 'Y') {
          y1 = stoll(s.substr(2, SZ(s) - 2));
        }
      }
    } else if (cnt == 1) {
      stringstream ss(line);
      string s;
      while (ss >> s) {
        if (s[0] == 'X') {
          x2 = stoll(s.substr(2, SZ(s) - 3));
        } else if (s[0] == 'Y') {
          y2 = stoll(s.substr(2, SZ(s) - 2));
        }
      }
    } else {
      stringstream ss(line);
      string s;
      while (ss >> s) {
        if (s[0] == 'X') {
          px = stoll(s.substr(2, SZ(s) - 3));
        } else if (s[0] == 'Y') {
          py = stoll(s.substr(2, SZ(s) - 2));
        }
      }
    }

    cnt++;
  }
  cout << ans << ENDL;

  return 0;
}