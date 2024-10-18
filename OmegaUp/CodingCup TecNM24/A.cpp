#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  double n;
  cin >> n;
  double ans = n * 567;
  ans /= 9;
  ans += 7492;
  ans *= 235;
  ans /= 47;
  ans -= 498;
  ll ans2 = ans;
  cout << (ans2 % 2 == 0 ? "Par" : "Impar") << "\n";
}