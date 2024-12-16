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
      "AdventofCode/Dia11/input.txt");

  string line;
  vi a;
  while (getline(file, line)) {
    stringstream ss(line);
    string x;
    while (ss >> x) a.pb(stoll(x));
  }
  FOR(i, 0, 75) {
    vi aa;
    for (auto x : a) {
      if (x == 0) {
        aa.pb(1);
        continue;
      }
      string s = to_string(x);
      if (SZ(s) % 2 == 0) {
        aa.pb(stoll(s.substr(0, SZ(s) / 2)));
        aa.pb(stoll(s.substr(SZ(s) / 2, SZ(s) / 2)));
        continue;
      }
      aa.pb(x * 2024);
    }
    a = aa;
  }

  cout << SZ(a) << ENDL;
  return 0;
}