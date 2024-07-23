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

string mergeAlternately(string word1, string word2) {
  string ans = "";
  int i = 0, j = 0;
  bool a = true;
  while (i < word1.size() || j < word2.size()) {
    if ((a && i < word1.size()) || j == word2.size()) {
      ans += word1[i];
      i++;
      a = false;
    } else if (j < word2.size()) {
      ans += word2[j];
      j++;
      a = true;
    }
  }
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  return 0;
}