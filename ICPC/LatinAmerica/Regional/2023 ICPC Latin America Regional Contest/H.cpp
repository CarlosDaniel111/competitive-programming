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

typedef double T;
const double EPS = 1e-9;
const double INF = 1e9;

struct Point {
  T x, y;

  // Operaciones Punto - Punto
  Point operator+(Point p) const { return {x + p.x, y + p.y}; }
  Point operator-(Point p) const { return {x - p.x, y - p.y}; }
  Point operator*(Point b) const {
    return {x * b.x - y * b.y, x * b.y + y * b.x};
  }

  // Operaciones Punto - Numero
  Point operator*(T d) const { return {x * d, y * d}; }
  Point operator/(T d) const {
    return {x / d, y / d};
  }  // Solo para punto flotante

  // Operaciones de comparacion para punto flotante
  bool operator<(Point p) const {
    return x < p.x - EPS || (abs(x - p.x) <= EPS && y < p.y - EPS);
  }
  bool operator==(Point p) const {
    return abs(x - p.x) <= EPS && abs(y - p.y) <= EPS;
  }
  bool operator!=(Point p) const { return !(*this == p); }

  T sq() { return x * x + y * y; }
  double norm() { return sqrt(sq()); }
  Point unit() { return *this / norm(); }

  // Operaciones generales:
  Point translate(Point v) { return *this + v; }
  Point scale(Point c, double factor) { return c + (*this - c) * factor; }
  Point rotate(double ang) {
    return {x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang)};
  }
  Point rot_around(double ang, Point c) { return c + (*this - c).rotate(ang); }
  Point perp() { return {-y, x}; }

  T dot(Point p) { return x * p.x + y * p.y; }
  T cross(Point p) const { return x * p.y - y * p.x; }
  T cross(Point a, Point b) const { return (a - *this).cross(b - *this); }
  double angle() const { return atan2(y, x); }

  friend ostream& operator<<(ostream& os, Point p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};

struct HalfPlane {
  Point p, pq;
  T angle;
  HalfPlane() {}
  HalfPlane(Point _p, Point _q)
      : p(_p), pq(_q - _p), angle(atan2(pq.y, pq.x)) {}
  bool operator<(HalfPlane b) const { return angle < b.angle; }
  bool out(Point q) { return pq.cross(q - p) < EPS; }
  Point intersect(HalfPlane l) {
    if (abs(pq.cross(l.pq)) < EPS) return Point{INF, INF};
    return l.p + l.pq * ((p - l.p).cross(pq) / l.pq.cross(pq));
  }
};  // Halfplane to the left of line

vector<Point> intersect(vector<HalfPlane> b) {
  vector<Point> bx = {Point{INF, INF}, Point{-INF, INF}, Point{-INF, -INF},
                      Point{INF, -INF}};
  for (int i = 0; i < 4; ++i) b.emplace_back(bx[i], bx[(i + 1) % 4]);
  sort(b.begin(), b.end());
  int n = b.size(), q = 1, h = 0;
  vector<HalfPlane> c(b.size() + 10);
  for (int i = 0; i < n; ++i) {
    while (q < h && b[i].out(c[h].intersect(c[h - 1]))) h--;
    while (q < h && b[i].out(c[q].intersect(c[q + 1]))) q++;
    c[++h] = b[i];
    if (q < h && abs(c[h].pq.cross(c[h - 1].pq)) < EPS) {
      if (c[h].pq.dot(c[h - 1].pq) <= 0) return {};
      h--;
      if (b[i].out(c[h].p)) c[h] = b[i];
    }
  }
  while (q < h - 1 && c[q].out(c[h].intersect(c[h - 1]))) h--;
  while (q < h - 1 && c[h].out(c[q].intersect(c[q + 1]))) q++;
  if (h - q <= 1) return {};
  c[h + 1] = c[q];
  vector<Point> s;
  for (int i = q; i < h + 1; ++i) s.push_back(c[i].intersect(c[i + 1]));
  return s;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  ld d;
  cin >> n >> d;
  vector<HalfPlane> hps(n);
  FOR(i, 0, n) {
    Point p1, p2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;

    if (p1.cross(p2) < 0) {
      swap(p1, p2);
    }
    hps[i] = HalfPlane(p1, p2);
  }

  auto can = [&](int mid) -> bool {
    vector<HalfPlane> curr(hps.begin(), hps.begin() + min(mid, n));
    vector<Point> pts = intersect(curr);
    for (auto pt : pts) {
      double di = sqrt(pt.x * pt.x + pt.y * pt.y);
      if (di >= d) {
        return false;
      }
    }
    return true;
  };

  int l = 1, r = n + 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  if (l == n + 1) {
    cout << "*" << ENDL;
    return 0;
  }

  cout << l << ENDL;

  return 0;
}