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
  vi vis(255, 0);
  ROF(i, SZ(s), 0) {
    if (vis[s[i]]) {
      cout << i + 1 << ENDL;
      return 0;
    }
    vis[s[i]] = 1;
  }
  cout << SZ(s) << ENDL;

  return 0;
}