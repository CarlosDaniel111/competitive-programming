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
      "AdventofCode/2025/Dia6/input.txt");

  string line;
  vector<vector<ll>> nums;
  ll ans = 0;
  while (getline(file, line)) {
    stringstream ss(line);
    string s;
    int i = 0;
    while (ss >> s) {
      if (s[0] == '*' or s[0] == '+') {
        ll curr = s[0] == '*';
        for (auto x : nums[i]) {
          if (s[0] == '*')
            curr *= x;
          else
            curr += x;
        }
        ans += curr;
        i++;
        continue;
      }
      ll num = stoll(s);
      if (i == SZ(nums)) {
        nums.pb(vector<ll>());
      }
      nums[i++].pb(num);
    }
  }
  cout << ans << ENDL;

  return 0;
}