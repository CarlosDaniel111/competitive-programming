#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll x;
  cin >> x;
  x *= 1e6;
  x *= 8;
  cout << ceil(log2(x)) << '\n';

  return 0;
}