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
constexpr double EPS = 1e-9;

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
  double sqDist(Point p) {
    return side(p) * side(p) / (double)v.sq();
  }  // si se trabaja con enteros
  Line perp(Point p) { return {p, p + v.perp()}; }
  Line translate(Point t) { return {v, c + v.cross(t)}; }
  Line shiftLeft(double dist) { return {v, c + dist * v.norm()}; }

  Point proj(Point p) {
    return p - v.perp() * side(p) / v.sq();
  }  // Punto en linea mas cercano a P
  Point refl(Point p) { return p - v.perp() * 2 * side(p) / v.sq(); }

  // Sirve para comparar si un punto A esta antes de B en una linea
  bool cmpProj(Point p, Point q) { return v.dot(p) < v.dot(q); }
};

bool areIntersect(Line l1, Line l2, Point& p) {
  T d = l1.v.cross(l2.v);
  if (abs(d) <= EPS) return false;      // cambiar a epsilon si es double
  p = (l2.v * l1.c - l1.v * l2.c) / d;  // requiere double
  return true;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, r;
  cin >> n >> m >> r;
  vector<Point> pts(n);
  FOR(i, 0, n) { cin >> pts[i].x >> pts[i].y; }
  vector<Line> lines;
  FOR(i, 0, m) {
    double a, b, c;
    cin >> a >> b >> c;
    lines.pb({a, b, c});
  }

  auto check = [&](int i, int j) -> bool {
    FOR(k, 0, m) {
      if (sgn(lines[k].side(pts[i])) != sgn(lines[k].side(pts[j]))) return true;
    }
    return false;
  };

  FOR(i, 0, n) {
    FOR(j, 0, n) {
      if (i == j) continue;
      if (!check(i, j)) {
        cout << "no" << ENDL;
        return 0;
      }
    }
  }

  int s = 0;
  FOR(i, 0, m) {
    FOR(j, i + 1, m) {
      Point pt;
      if (areIntersect(lines[i], lines[j], pt)) {
        if (pt.x * pt.x + pt.y * pt.y < r * r) s++;
      }
    }
  }
  if (s + m + 1 == n) {
    cout << "yes" << ENDL;
  } else {
    cout << "no" << ENDL;
  }

  return 0;
}