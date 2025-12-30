#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

void solve() {
  int n, k;
  cin >> n >> k;
  int x, y;
  vector<double> ang(n * 2);
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    ang[i] = atan2(y, x);
  }
  sort(ang.begin(), ang.begin() + n);
  for (int i = 0; i < n; i++) ang[i + n] = ang[i] + 2.0 * PI;
  double ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, ang[i + k] - ang[i]);
  }
  cout << setprecision(10) << fixed;
  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}