#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve() {
  string s, t;
  cin >> s >> t;
  int ans = 10000;
  FOR(i, 0, SZ(t)) {
    int p1 = i, cnt = 0;
    for (int j = 0; j < SZ(s) && p1 < SZ(t); j++) {
      if (s[j] == t[p1])
        p1++;
    }
    int curr = i + (SZ(t) - p1);
    ans = min(ans, curr);
  }
  cout << ans + SZ(s) << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}