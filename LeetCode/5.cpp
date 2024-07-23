#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

class Solution {
 public:
};

string reverseVowels(string s) {
  int n = s.size();
  vector<char> c;
  for (int i = 0; i < n; i++) {
    if (tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' ||
        tolower(s[i]) == 'o' || tolower(s[i]) == 'u') {
      c.push_back(s[i]);
    }
  }
  reverse(c.begin(), c.end());
  string ans = "";
  int curr = 0;
  for (int i = 0; i < n; i++) {
    if (tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' ||
        tolower(s[i]) == 'o' || tolower(s[i]) == 'u') {
      ans += c[curr++];
    } else {
      ans += s[i];
    }
  }
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  return 0;
}