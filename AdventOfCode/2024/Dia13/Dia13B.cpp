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

std::tuple<bool, long long, long long> check_linear_combination(
    const long long ax, const long long ay, const long long bx,
    const long long by, const long long cx, const long long cy) {
  if ((ax * by) == (bx * ay)) exit(0);
  const long long n1 = (cx * by - cy * bx) / (ax * by - ay * bx);
  const long long n2 = (cx * ay - cy * ax) / (bx * ay - by * ax);

  if (n1 * ax + n2 * bx != cx) return {false, -1, -1};
  if (n1 * ay + n2 * by != cy) return {false, -1, -1};
  if (n1 < 0 || n2 < 0) return {false, -1, -1};
  return {true, n1, n2};
}

/*
  94x + 22y = 8400
  34x + 67y = 5400

  x1X + x2Y = px
  y1X + y2Y = py
*/

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
      auto [p, n1, n2] = check_linear_combination(x1, y1, x2, y2, px, py);
      if (p) ans += (n1 * 3 + n2);
      continue;
    }
    if (cnt == 0) {
      stringstream ss(line);
      string s;
      while (ss >> s) {
        if (s[0] == 'X') {
          x1 = stoi(s.substr(2, SZ(s) - 3));
        } else if (s[0] == 'Y') {
          y1 = stoi(s.substr(2, SZ(s) - 2));
        }
      }
    } else if (cnt == 1) {
      stringstream ss(line);
      string s;
      while (ss >> s) {
        if (s[0] == 'X') {
          x2 = stoi(s.substr(2, SZ(s) - 3));
        } else if (s[0] == 'Y') {
          y2 = stoi(s.substr(2, SZ(s) - 2));
        }
      }
    } else {
      stringstream ss(line);
      string s;
      while (ss >> s) {
        if (s[0] == 'X') {
          px = stoi(s.substr(2, SZ(s) - 3));
          px += 10000000000000;
        } else if (s[0] == 'Y') {
          py = stoi(s.substr(2, SZ(s) - 2));
          py += 10000000000000;
        }
      }
    }

    cnt++;
  }
  cout << ans << ENDL;

  return 0;
}