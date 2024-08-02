#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

struct Point {
  ll x, y;

  ll cross(Point p) const { return x * p.y - y * p.x; }

  friend ostream& operator<<(ostream& os, Point p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};

vector<ll> prefix;
ll area;
vector<Point> poly;
int n;

ll f(int a, int b) {
  ll curr = prefix[b] - prefix[a];
  ll A1 = abs(curr + poly[b % n].cross(poly[a % n]));
  ll A2 = area - A1;
  return max(A1, A2);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  poly.resize(n);
  FOR(i, 0, n) {
    cin >> poly[i].x >> poly[i].y;
  }

  area = 0;
  FOR(i, 0, n) {
    area += poly[i].cross(poly[(i + 1) % n]);
  }

  prefix.assign(n * 2 + 1, 0);
  FOR(i, 1, 2 * n + 1) {
    prefix[i] = prefix[i - 1] + poly[(i - 1) % n].cross(poly[i % n]);
  }

  ll ans = 0;

  FOR(i, 0, n) {
    int l = i + 2;
    int r = i + n - 2;
    while (r - l >= 5) {
      int m1 = l + (r - l) / 3;
      int m2 = r - (r - l) / 3;
      ll f1 = f(i, m1);
      ll f2 = f(i, m2);
      if (f1 > f2)  // Minimo de f(x)
        l = m1;
      else
        r = m2;
    }
    ll mn = LLONG_MAX;
    FOR(j, l, r + 1)
    mn = min(mn, f(i, j));

    ans = max(ans, mn);
  }

  cout << ans << " " << area - ans << ENDL;

  return 0;
}