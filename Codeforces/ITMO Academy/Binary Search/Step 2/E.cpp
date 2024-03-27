#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
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

  double c;
  cin >> c;
  double l = 0, r = 1e10;
  FOR(i, 0, 100) {
    double mid = (l + r) / 2;
    if (mid * mid + sqrt(mid) >= c) {
      r = mid;
    } else {
      l = mid;
    }
  }

  cout << setprecision(20) << r << ENDL;

  return 0;
}