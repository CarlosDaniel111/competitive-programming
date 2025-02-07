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

string s;
set<string> pat;

ll dp[200];

ll solve(ll pos) {
  if (pos == SZ(s)) return 1;
  ll &ans = dp[pos];
  if (ans != -1) return ans;
  ans = 0;
  FOR(i, 1, SZ(s) - pos + 1) {
    if (pat.count(s.substr(pos, i))) {
      ans += solve(pos + i);
    }
  }
  return ans;
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ifstream file(
      "/Users/CarlosBeltran/Documents/ICPC/competitive-programming/"
      "AdventofCode/Dia20/input.txt");

  string line;
  bool isPatron = true;

  ll ans = 0;
  while (getline(file, line)) {
    if (SZ(line) == 0) {
      isPatron = false;
      continue;
    }
    if (isPatron) {
      vector<string> pats = split(line, ',');
      FOR(i, 0, SZ(pats)) {
        if (i == 0) {
          pat.insert(pats[i]);
        } else {
          pat.insert(pats[i].substr(1));
        }
      }
      continue;
    }
    s = line;
    memset(dp, -1, sizeof(dp));
    ans += solve(0);
  }
  cout << ans << ENDL;

  return 0;
}