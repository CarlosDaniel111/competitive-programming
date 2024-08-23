#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'

const double PI = acos(-1.0);

double eval(double l, double r, double a) {
  double lb = l * cos(a);
  double la = l * sin(a);

  double rG = r + lb;

  return (la * PI / 3) * (r * r + rG * rG + r * rG);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  cout << setprecision(8) << fixed;

  while (n--) {
    int la, ra;
    cin >> la >> ra;

    double l = 0, r = PI / 2;
    FOR(i, 0, 40) {
      double m1 = l + (r - l) / 3;
      double m2 = r - (r - l) / 3;
      double f1 = eval(la * 1.0, ra * 1.0, m1);
      double f2 = eval(la * 1.0, ra * 1.0, m2);
      if (f1 < f2) {
        l = m1;
      } else {
        r = m2;
      }
    }
    cout << PI - l << ENDL;
  }
  return 0;
}