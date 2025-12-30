#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
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
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;
  vector<double> a(n);
  FOR(i, 0, n) cin >> a[i];

  auto can = [&](double x) -> bool {
    vector<double> pref(n + 1, 0);
    FOR(i, 0, n) { pref[i + 1] = pref[i] + (a[i] - x); }
    vector<double> l(n);
    int lisSz = 0;

    for (int i = 1; i <= n; i++) {
      if (pref[i] < 0) continue;
      int pos = lower_bound(l.begin(), l.begin() + lisSz, pref[i]) - l.begin();
      l[pos] = pref[i];
      if (pos == lisSz) {
        lisSz = pos + 1;
      }
      if (i == n) return pos + 1 >= k;
    }
    return 0;
  };

  double l = 0, r = 1005;
  FOR(_, 0, 200) {
    double mid = (l + r) / 2.0;
    if (can(mid))
      l = mid;
    else
      r = mid;
  }
  cout << setprecision(9) << fixed;
  cout << l << ENDL;

  return 0;
}