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

constexpr double EPS = 1e-9;

typedef double T;

int sgn(T x) { return (T(0) < x) - (x < T(0)); }

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

bool inDisk(Point a, Point b, Point p) { return (a - p).dot(b - p) <= EPS; }
bool onSegment(Point a, Point b, Point p) {
  return abs(a.cross(b, p)) <= EPS && inDisk(a, b, p);
}

int inPolygon(vector<Point> poly, Point p) {
  int n = SZ(poly), ans = 0;
  FOR(i, 0, n) {
    Point p1 = poly[i], p2 = poly[(i + 1) % n];
    if (p1.y > p2.y) swap(p1, p2);
    if (onSegment(p1, p2, p)) return 0;
    ans ^= (p1.y <= p.y && p.y < p2.y && p.cross(p1, p2) > 0);
  }
  return ans ? 1 : -1;
}

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

int orient(Point a, Point b, Point c) { return sgn(a.cross(b, c)); }

bool isInsideTriangle(Point a, Point b, Point c, Point p) {
  int o1 = orient(a, b, p);
  int o2 = orient(b, c, p);
  int o3 = orient(c, a, p);

  return (o1 == o2 && o2 == o3 && o1 != 0);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  double h;
  cin >> n >> h;
  vector<tuple<double, double, double>> a(n);
  int disp = 0;
  FOR(i, 0, n) {
    double x, y, z;
    cin >> x >> y >> z;
    a[i] = {z, x, y};
    if (z >= h) disp++;
  }
  Point c;
  cin >> c.x >> c.y;

  if (n < 3) {
    cout << -1 << ENDL;
    return 0;
  }
  auto can = [&](int m) -> bool {
    m += disp;
    vector<Point> pts(m);
    FOR(i, 0, m) {
      auto [_, x, y] = a[i];
      pts[i] = {x, y};
    }
    vector<Point> ch = convexHull(pts);
    if (SZ(ch) < 3) return false;

    if (inPolygon(ch, c) != 1) return false;

    if (SZ(ch) == 4) {
      if (!onSegment(ch[0], ch[2], c) or !onSegment(ch[1], ch[3], c))
        return true;
      FOR(i, 0, m) {
        if (inPolygon(ch, pts[i]) != -1 && !onSegment(ch[0], ch[2], pts[i]) &&
            !onSegment(ch[1], ch[3], pts[i]))
          return true;
      }
      return false;
    }
    FOR(i, 1, SZ(ch) - 1) {
      if (isInsideTriangle(ch[0], ch[i], ch[i + 1], c)) return true;
    }
    return false;
  };
  sort(a.rbegin(), a.rend());
  int l = 0, r = n - disp;
  while (l < r) {
    int mid = (l + r) / 2;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (!can(l)) {
    cout << -1 << ENDL;
    return 0;
  }
  cout << setprecision(9) << fixed;
  cout << max(0.0, h - get<0>(a[l - 1 + disp])) << ENDL;

  return 0;
}