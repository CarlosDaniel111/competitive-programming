#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll x;
  cin >> x;

  ll y = 0;
  int l = 0, r = 62;
  while (l < r) {
    if (y + (1ll << l) + (1ll << r) <= x) {
      y += 1ll << l;
      y += 1ll << r;
      ++l;
    } else if (y) {
      ++l;
    }
    --r;
  }
  if (l == r && y + (1ll << l) <= x) {
    y += 1ll << l;
  }
  cout << y << '\n';

  return 0;
}