#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
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
  Point operator*(Point b) const { return {x * b.x - y * b.y, x * b.y + y * b.x}; }

  // Operaciones Punto - Numero
  Point operator*(T d) const { return {x * d, y * d}; }
  Point operator/(T d) const { return {x / d, y / d}; }  // Solo para punto flotante

  // Operaciones de comparacion para punto flotante
  bool operator<(Point p) const { return x < p.x - EPS || (abs(x - p.x) <= EPS && y < p.y - EPS); }
  bool operator==(Point p) const { return abs(x - p.x) <= EPS && abs(y - p.y) <= EPS; }
  bool operator!=(Point p) const { return !(*this == p); }

  T sq() { return x * x + y * y; }
  double norm() { return sqrt(sq()); }
  Point unit() { return *this / norm(); }

  // Operaciones generales:
  Point translate(Point v) { return *this + v; }
  Point scale(Point c, double factor) { return c + (*this - c) * factor; }
  Point rotate(double ang) { return {x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang)}; }
  Point rot_around(double ang, Point c) { return c + (*this - c).rotate(ang); }
  Point perp() { return {-y, x}; }

  T dot(Point p) { return x * p.x + y * p.y; }
  T cross(Point p) const { return x * p.y - y * p.x; }
  T cross(Point a, Point b) const { return (a - *this).cross(b - *this); }
  double angle() { return atan2(y, x); }
};

double dist(Point p1, Point p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }

Point circlePoint(Point c, double r, double ang) {
  return Point{c.x + cos(ang) * r, c.y + sin(ang) * r};
}

int circleCircle(Point o1, double r1, Point o2, double r2, pair<Point, Point>& out) {
  Point d = o2 - o1;
  double d2 = d.sq();
  if (abs(d2) < EPS) {
    return 0;
  }
  double pd = (d2 + r1 * r1 - r2 * r2) / 2;
  double h2 = r1 * r1 - pd * pd / d2;
  if (h2 >= -EPS) {
    Point p = o1 + d * pd / d2, h = d.perp() * sqrt(h2 / d2);
    out = {p - h, p + h};
  }
  return 1 + sgn(h2);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vi L(n);
  FOR(i, 0, n) {
    cin >> L[i];
  }
  Point p;
  cin >> p.x >> p.y;
  vi inner(n), outer(n);
  outer[0] = inner[0] = L[0];
  FOR(i, 1, n) {
    outer[i] = outer[i - 1] + L[i];
    inner[i] = min(abs(outer[i - 1] - L[i]), abs(inner[i - 1] - L[i]));
    if (inner[i - 1] <= L[i] && L[i] <= outer[i - 1]) inner[i] = 0;
  }
  if (p.norm() > outer[n - 1]) p = circlePoint({0.0, 0.0}, outer[n - 1], p.angle());
  if (p.norm() < inner[n - 1]) p = circlePoint({0.0, 0.0}, inner[n - 1], p.angle());
  vector<Point> ans;
  ans.pb(p);
  for (int i = n - 2; i >= 0; i--) {
    pair<Point, Point> out;
    int inter = circleCircle({0, 0}, outer[i], p, L[i + 1], out);
    if (inter != 0) {
      ans.pb(out.first);
      p = out.first;
      continue;
    }
    inter = circleCircle({0, 0}, inner[i], p, L[i + 1], out);
    if (inter != 0) {
      ans.pb(out.first);
      p = out.first;
      continue;
    }
    p = circlePoint({0, 0}, p.norm() - L[i + 1], p.angle());
    ans.pb(p);
  }
  cout << setprecision(5) << fixed;
  reverse(ALL(ans));
  for (auto p : ans) {
    cout << p.x << " " << p.y << ENDL;
  }

  // cout << dist({7.9925231289, 0.3457947851}, {5, 3}) << ENDL;
  return 0;
}