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
      "AdventofCode/2025/Dia10/input.txt");

  string line;
  int ans = 0;
  while (getline(file, line)) {
    vector<string> input = split(line, ' ');
    int goal = 0;
    string pat = input[0];
    FOR(i, 1, SZ(pat) - 1) {
      if (pat[i] == '#') goal |= (1 << (i - 1));
    }
    vi btn;
    FOR(i, 1, SZ(input) - 1) {
      string s = input[i].substr(1, SZ(input[i]) - 2);
      vector<string> nums = split(s, ',');
      int curr = 0;
      for (auto num : nums) {
        int x = stoi(num);
        curr = curr xor (1 << x);
      }
      btn.pb(curr);
    }
    int n = SZ(btn);
    vector<int> dp(1 << (SZ(pat) - 2), -1);
    auto solve = [&](auto self, int msk) -> int {
      if (msk == goal) return 0;
      int& ans = dp[msk];
      if (ans != -1) return ans;
      ans = 1e9;
      FOR(i, 0, n) { ans = min(ans, self(self, msk xor btn[i]) + 1); }
      return ans;
    };
    ans += solve(solve, 0);
  }
  cout << ans << ENDL;

  return 0;
}