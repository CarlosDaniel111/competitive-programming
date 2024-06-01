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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  double s;
  cin >> s;
  auto check = [&](double x) -> bool {
    double ans = 0;
    for (double i = 1; i <= x; i++) {
      ans += floor(sqrt(x * x - i * i));
    }
    ans *= 4;
    return (ans > s);
  };
  double l = 0, r = 1e5;
  FOR(_, 0, 500) {
    double mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << setprecision(8) << fixed;
  cout << r << ENDL;

  return 0;
}