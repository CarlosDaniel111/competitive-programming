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
  ll r;
  cin >> r;
  ll x = 0, y = r;
  ll ans = 0;
  while (y) {
    if (x * x + y * y < (r + 1) * (r + 1)) {
      ans += (x * x + y * y >= r * r);
      x++;
    } else
      x--, y--;
  }
  cout << ans * 4 << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}