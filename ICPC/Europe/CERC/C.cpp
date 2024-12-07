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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  int n;
  cin >> n;
  cin >> s;
  bool fullT = true;
  FOR(i, 0, n) {
    if (s[i] != 'T') {
      fullT = false;
      break;
    }
  }
  if (fullT) {
    cout << 2 * n + 1 << ENDL;
    return 0;
  }
  double ans = n;
  if (s[0] == 'C') {
    ans -= 0.5;
    ans += PI / 2;
  } else
    ans++;
  if (s[n - 1] == 'C') {
    ans -= 0.5;
    ans += PI / 2;
  } else
    ans++;

  int l = 0;
  while (s[l] == 'T') l++;
  int r = n - 1;
  while (s[r] == 'T') r--;
  ans += r - l + 1;
  if (s[l] == 'C') ans -= 0.5;
  if (s[r] == 'C') ans -= 0.5;

  // Casos especiales
  if (l != 0) {
    // △o
    if (s[l] == 'C') {
      double ca = l;
      double co = sqrt(3.0) / 2 - 0.5;
      double hip = sqrt(ca * ca + co * co);
      double tToC = sqrt(hip * hip - 0.25);
      ans += tToC;

      double sinb = co / (hip);
      double b = asin(sinb);
      double cosa = 1.0 / (2 * hip);
      double a = acos(cosa);
      ans += (PI / 2 - a - b) / 2;
      // △▢
    } else {
      double co = 1.0 - sqrt(3.0) / 2;
      double ca = l - 0.5;
      ans += sqrt(co * co + ca * ca);
    }
  }

  if (r != n - 1) {
    // o△
    if (s[r] == 'C') {
      double ca = n - 1 - r;
      double co = sqrt(3.0) / 2 - 0.5;
      double hip = sqrt(ca * ca + co * co);
      double tToC = sqrt(hip * hip - 0.25);
      ans += tToC;

      double sinb = co / (hip);
      double b = asin(sinb);
      double cosa = 1.0 / (2 * hip);
      double a = acos(cosa);
      ans += (PI / 2 - a - b) / 2;
      // △▢
    } else {
      double co = 1.0 - sqrt(3.0) / 2;
      double ca = n - 1.5 - r;
      ans += sqrt(co * co + ca * ca);
    }
  }
  cout << setprecision(12) << fixed;
  cout << ans << ENDL;

  return 0;
}