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

typedef double T;
constexpr double EPS = 1e-9;

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
  double angle() const { return atan2(y, x); }

  friend ostream& operator<<(ostream& os, Point p) {
    return os << p.x << " " << p.y;
  }
};

double angle(Point v, Point w) { return acos(clamp(v.dot(w) / v.norm() / w.norm(), -1.0, 1.0)); }

struct Line {
  Point v;
  T c;

  // De vector direccional v y offset c
  Line(Point v, T c) : v(v), c(c) {}

  // De la ecuacion ax+by=c
  Line(T a, T b, T c) : v({b, -a}), c(c) {}

  // De punto P a punto Q
  Line(Point p, Point q) : v(q - p), c(v.cross(p)) {}

  // 0 si se encuentra en la linea, > 0 arriba, < 0 abajo
  T side(Point p) { return v.cross(p) - c; }

  double dist(Point p) { return abs(side(p)) / v.norm(); }
  double sqDist(Point p) { return side(p) * side(p) / (double)v.sq(); }  // si se trabaja con enteros
  Line perp(Point p) { return {p, p + v.perp()}; }
  Line translate(Point t) { return {v, c + v.cross(t)}; }
  Line shiftLeft(double dist) { return {v, c + dist * v.norm()}; }

  Point proj(Point p) { return p - v.perp() * side(p) / v.sq(); }  // Punto en linea mas cercano a P
  Point refl(Point p) { return p - v.perp() * 2 * side(p) / v.sq(); }

  // Sirve para comparar si un punto A esta antes de B en una linea
  bool cmpProj(Point p, Point q) {
    return v.dot(p) < v.dot(q);
  }
};

int n;
vector<Point> p, ans;

Point getPoint(double c, Point a, Point b) {
  a = a.unit();
  b = b.unit();
  Point r = (a + b) / 2.0;
  r = r.unit();
  return r * c;
}

double segPoint(Point a, Point b, Point p) {
  if (a != b) {
    Line l(a, b);
    if (l.cmpProj(a, p) && l.cmpProj(p, b))
      return l.dist(p);
  }
  return min((p - a).norm(), (p - b).norm());
}

bool check(Point pt) {
  FOR(i, 0, n) {
    if (segPoint(p[i], p[(i + 1) % n], pt) < 4000) return false;
  }
  return true;
}

double dist(Point p1, Point p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n;
  p.resize(n);
  FOR(i, 0, n) {
    cin >> p[i].x >> p[i].y;
  }

  FOR(i, 0, n) {
    Point l = p[i], m = p[(i + 1) % n], r = p[(i + 2) % n];
    Point v1 = l - m;
    Point v2 = r - m;
    if (v1.cross(v2) < 0) continue;
    double angulo = angle(v1, v2) / 2.0;
    Point curr = getPoint(4000.1 / sin(angulo), v1, v2) + m;
    if (check(curr)) {
      ans.pb(curr);
    }
  }

  int m = SZ(ans);
  FOR(i, 0, m) {
    FOR(j, i + 1, m) {
      if ((ans[j] - ans[i]).norm() >= 8000) {
        cout << setprecision(8) << fixed;
        cout << ans[i] << ENDL;
        cout << ans[j] << ENDL;
        return 0;
      }
    }
  }
  cout << "impossible" << ENDL;

  return 0;
}