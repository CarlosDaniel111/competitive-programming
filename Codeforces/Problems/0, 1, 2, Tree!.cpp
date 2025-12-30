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
  int a, b, c;
  cin >> a >> b >> c;
  if (a + 1 != c) {
    cout << -1 << ENDL;
    return;
  }
  if (a + b + c == 1) {
    cout << 0 << ENDL;
    return;
  }

  int ans = 1, currLevel = 1, nxtLevel = 0;
  FOR(i, 0, a + b) {
    if (!currLevel) {
      currLevel = nxtLevel;
      nxtLevel = 0;
      ans++;
    }
    currLevel--;
    nxtLevel += 1 + (i < a);
  }
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}