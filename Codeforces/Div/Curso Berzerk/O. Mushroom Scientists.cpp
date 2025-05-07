#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using ld = long double;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

const ld EPS = 1e-11;

ld mlog(ld x) { return (x < EPS ? log(x + EPS) : log(x)); }

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ld s, a, b, c;
  cin >> s >> a >> b >> c;
  if (a == 0 && b == 0 && c == 0) {
    cout << a << " " << a << " " << a << ENDL;
    return 0;
  }

  auto f = [&](ld x) -> pair<ld, ld> {
    ld l = 0, r = x;
    FOR(i, 0, 1000) {
      ld m1 = l + (r - l) / 3;
      ld m2 = r - (r - l) / 3;
      ld f1 = mlog(m1) * b + mlog(x - m1) * c;
      ld f2 = mlog(m2) * b + mlog(x - m2) * c;
      if (f1 < f2)  // Maximo de f(x)
        l = m1;
      else
        r = m2;
    }
    return {mlog(l) * b + mlog(x - l) * c, l};
  };

  ld l = 0, r = s;
  FOR(i, 0, 1000) {
    ld m1 = l + (r - l) / 3;
    ld m2 = r - (r - l) / 3;
    ld f1 = mlog(m1) * a + f(s - m1).first;
    ld f2 = mlog(m2) * a + f(s - m2).first;
    if (f1 < f2)  // Maximo de f(x)
      l = m1;
    else
      r = m2;
  }
  cout << setprecision(12) << fixed;
  ld x = l, y = f(s - l).second, z = s - x - y;
  cout << x << " " << y << " " << z << ENDL;

  return 0;
}