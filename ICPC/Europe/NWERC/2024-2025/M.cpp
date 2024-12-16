#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using ld = long double;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

typedef ld T;

struct Point {
  T x, y;

  // Operaciones Punto - Punto
  Point operator+(Point p) const { return {x + p.x, y + p.y}; }
  Point operator-(Point p) const { return {x - p.x, y - p.y}; }

  // Operaciones Punto - Numero
  Point operator*(T d) const { return {x * d, y * d}; }

  T dot(Point p) { return x * p.x + y * p.y; }
  T cross(Point p) const { return x * p.y - y * p.x; }

  friend ostream& operator<<(ostream& os, Point p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};

ld areaPolygon(vector<Point> p) {
  ld area = 0.0;
  int n = SZ(p);
  FOR(i, 0, n) { area += p[i].cross(p[(i + 1) % n]); }
  return abs(area) / 2.0;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<Point> pts(n);
  FOR(i, 0, n) { cin >> pts[i].x >> pts[i].y; }
  vector<Point> pref(n + 1), suff(n + 1);
  pref[0] = {0, 0};
  FOR(i, 0, n) pref[i + 1] = pref[i] + pts[i];

  ld ans = 0.0;
  FOR(j, 1, n + 1) {
    Point p1 = (pts[j - 1] * (j - 1)) - pref[j - 1];
    Point p2 = (pref[n] - pref[j]) - (pts[j - 1] * (n - j));
    ans += p1.cross(p2);
  }
  ans /= 2;
  ld area = areaPolygon(pts);
  cout << setprecision(12) << fixed;
  cout << ans / area << ENDL;

  return 0;
}