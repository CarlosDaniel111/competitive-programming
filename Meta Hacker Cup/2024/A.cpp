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

const double INF = 1e9;

void solve() {
  int n;
  cin >> n;
  double mn = 0, mx = 1e9;
  FOR(i, 1, n + 1) {
    int l, r;
    cin >> l >> r;
    double mni = (r == 0 ? INF : (1.0 * i) / (r * 1.0));
    double mxi = (l == 0 ? INF : (1.0 * i) / (l * 1.0));
    mn = max(mn, mni);
    mx = min(mx, mxi);
  }
  cout << setprecision(9) << fixed;
  if (mn <= mx) {
    cout << mn << ENDL;
  } else {
    cout << "-1" << ENDL;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  FOR(i, 1, t + 1) {
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}