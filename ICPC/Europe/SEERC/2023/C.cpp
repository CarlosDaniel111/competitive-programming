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

typedef double T;
const double EPS = 1e-9;

struct Point {
  T x, y;

  // Operaciones Punto - Punto
  Point operator+(Point p) const { return {x + p.x, y + p.y}; }
  Point operator-(Point p) const { return {x - p.x, y - p.y}; }
  Point operator*(Point b) const {
    return {x * b.x - y * b.y, x * b.y + y * b.x};
  }

  bool operator<(Point p) const {
    return x < p.x - EPS || (abs(x - p.x) <= EPS && y < p.y - EPS);
  }
  bool operator==(Point p) const {
    return abs(x - p.x) <= EPS && abs(y - p.y) <= EPS;
  }

  // Operaciones Punto - Numero
  Point operator*(T d) const { return {x * d, y * d}; }
  Point operator/(T d) const {
    return {x / d, y / d};
  }  // Solo para punto flotante

  T sq() { return x * x + y * y; }
  double norm() { return sqrt(sq()); }
  Point perp() { return {-y, x}; }
  T cross(Point p) const { return x * p.y - y * p.x; }
  T cross(Point a, Point b) const { return (a - *this).cross(b - *this); }
};

Point circumCenter(const Point& A, const Point& B, const Point& C) {
  Point b = C - A, c = B - A;
  return A + (b * c.sq() - c * b.sq()).perp() / b.cross(c) / 2;
}

pair<Point, double> mec(vector<Point> pts) {
  shuffle(ALL(pts), mt19937(time(0)));
  Point o = pts[0];
  double r = 0, EPS = 1 + 1e-8;
  FOR(i, 0, SZ(pts)) if ((o - pts[i]).norm() > r * EPS) {
    o = pts[i], r = 0;
    FOR(j, 0, i) if ((o - pts[j]).norm() > r * EPS) {
      o = (pts[i] + pts[j]) / 2;
      r = (o - pts[i]).norm();
      FOR(k, 0, j) if ((o - pts[k]).norm() > r * EPS) {
        o = circumCenter(pts[i], pts[j], pts[k]);
        r = (o - pts[i]).norm();
      }
    }
  }
  return {o, r};
}

T orient(Point a, Point b, Point c) { return a.cross(b, c); }

vector<Point> convexHull(vector<Point> pts) {
  if (SZ(pts) <= 1) return pts;
  sort(ALL(pts));
  vector<Point> h(SZ(pts) + 1);
  int s = 0, t = 0;
  for (int it = 2; it--; s = --t, reverse(ALL(pts)))
    for (Point p : pts) {
      while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0)
        t--;  // quitar = si se incluye colineares
      h[t++] = p;
    }
  return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

void reorder(vector<Point>& p) {
  if (orient(p[0], p[1], p[2]) < -EPS) reverse(ALL(p));
  int pos = 0;
  FOR(i, 1, SZ(p))
  if (Point{p[i].y, p[i].x} < Point{p[pos].y, p[pos].x}) pos = i;
  rotate(p.begin(), p.begin() + pos, p.end());
}
vector<Point> minkowski_sum(vector<Point> p, vector<Point> q) {
  if (min(SZ(p), SZ(q)) < 3) {
    vector<Point> v;
    for (Point pp : p)
      for (Point qq : q) v.pb(pp + qq);
    return convexHull(v);
  }
  reorder(p);
  reorder(q);
  FOR(i, 0, 2) p.pb(p[i]), q.pb(q[i]);
  vector<Point> r;
  int i = 0, j = 0;
  while (i + 2 < SZ(p) || j + 2 < SZ(q)) {
    r.pb(p[i] + q[j]);
    auto cross = (p[i + 1] - p[i]).cross(q[j + 1] - q[j]);
    i += cross >= -EPS;
    j += cross <= EPS;
  }
  return r;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<Point> p(n);
  FOR(i, 0, n) {
    cin >> p[i].x >> p[i].y;
    p[i] = p[i] * -1;
  }

  int m;
  cin >> m;
  vector<Point> q(m);
  FOR(i, 0, m) { cin >> q[i].x >> q[i].y; }

  p = convexHull(p);
  q = convexHull(q);
  vector<Point> pq = minkowski_sum(p, q);

  auto [o, r] = mec(pq);
  cout << setprecision(12) << fixed;
  cout << r << " " << o.x << " " << o.y << ENDL;

  return 0;
}