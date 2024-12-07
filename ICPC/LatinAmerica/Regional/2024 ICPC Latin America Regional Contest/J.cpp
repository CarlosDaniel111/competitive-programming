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

const double PI = acos(-1.0);

inline double DEG_to_RAD(double d) { return (d * PI / 180.0); }

// tan x = co / ca;
// ca = co / tan x;
signed main() {
  cin.tie(0)->sync_with_stdio(0);

  double ang;
  int n;
  cin >> ang >> n;
  double tn = tan(DEG_to_RAD(ang));
  double l = -1, r = -1;
  vector<pi> a(n);
  FOR(i, 0, n) { cin >> a[i].first >> a[i].second; }
  sort(ALL(a));
  double ans = 0;
  FOR(i, 0, n) {
    int x = a[i].first, h = a[i].second;
    if (x > r) {
      ans += r - l;
      l = x;
    }
    r = max(r, 1.0 * h / tn + x);
  }
  ans += r - l;
  cout << setprecision(9) << fixed;
  cout << ans << ENDL;

  return 0;
}