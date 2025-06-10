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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;
  int n = SZ(s);
  int i = 0;
  int ans = 0;
  while (i < n) {
    int j = i;
    while (j < n && s[i] == s[j]) j++;
    ans = max(ans, j - i);
    i = j;
  }
  cout << ans << ENDL;

  return 0;
}