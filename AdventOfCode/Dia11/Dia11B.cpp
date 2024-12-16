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
  map<ll, ll> cnt;
  for (auto x : a) cnt[x]++;
  ll ans = 0;
  FOR(i, 0, 75) {
    map<ll, ll> cnt2;
    for (auto [x, c] : cnt) {
      if (x == 0) {
        cnt2[1] += c;
        continue;
      }
      string s = to_string(x);
      if (SZ(s) % 2 == 0) {
        ll xx = stoll(s.substr(0, SZ(s) / 2)),
           yy = stoll(s.substr(SZ(s) / 2, SZ(s) / 2));
        cnt2[xx] += c;
        cnt2[yy] += c;
        continue;
      }
      cnt2[x * 2024] += c;
    }
    cnt = cnt2;
  }
  for (auto [x, y] : cnt) {
    ans += y;
  }
  cout << ans << ENDL;
  return 0;
}