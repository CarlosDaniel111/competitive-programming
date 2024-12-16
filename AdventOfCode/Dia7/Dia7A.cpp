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

#define isOn(S, j) ((S >> j) & 1)

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
      "AdventofCode/Dia7/input.txt");

  string line;
  ll ans = 0;
  while (getline(file, line)) {
    vector<string> inp = split(line, ' ');
    ll tot = stoll(inp[0].substr(0, SZ(inp[0]) - 1));
    vector<ll> a;
    FOR(i, 1, SZ(inp)) { a.pb(stoll(inp[i])); }
    ll n = SZ(inp) - 2;

    auto solve = [&](auto self, ll i, ll curr) -> ll {
      if (i == n) {
        return curr == tot;
      }
      if (self(self, i + 1, curr + a[i + 1])) return true;
      if (self(self, i + 1, curr * a[i + 1])) return true;
      string cad = to_string(curr) + to_string(a[i + 1]);
      if (self(self, i + 1, stoll(cad))) return true;
      return false;
    };

    if (solve(solve, 0, a[0])) {
      ans += tot;
    }
  }
  cout << ans << ENDL;

  return 0;
}