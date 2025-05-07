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

#define isOn(S, j) ((S >> j) & 1)

void solve() {
  int l, r;
  cin >> l >> r;
  int ans = 0;
  ROF(i, 30, 0) {
    if (isOn(r, i)) {
      ans += (1 << i);
      if (!isOn(l, i)) break;
    }
  }
  if (ans == r) {
    cout << ans << " " << ans - 1 << " " << ans - 2 << ENDL;
  } else {
    cout << ans - 1 << " " << ans << " " << ans + 1 << ENDL;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}