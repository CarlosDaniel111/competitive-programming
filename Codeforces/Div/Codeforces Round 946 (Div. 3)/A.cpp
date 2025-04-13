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
  int x, y;
  cin >> x >> y;
  int ans = 0;
  while (y > 0) {
    x -= 7, y -= 2;
    ans++;
  }
  if (y == -1) {
    y++;
    x -= 4;
  }
  ans += max(0, (x + 14) / 15);
  cout << ans << '\n';
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}