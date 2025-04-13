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
  ll x, y, k;
  cin >> x >> y >> k;
  while (k) {
    ll falta = x % y;
    if (falta < y - 1) {
      ll aux = min(y - 1 - falta, k);
      x += aux;
      k -= aux;
      continue;
    }
    x++, k--;
    while (x % y == 0) x /= y;
    if (x == 1) {
      cout << k % (y - 1) + 1 << ENDL;
      return;
    }
  }
  cout << x << ENDL;
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