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

typedef long long T;

struct Point {
  T x, y;

  // Operaciones Punto - Punto
  Point operator+(Point p) const { return {x + p.x, y + p.y}; }
  Point operator-(Point p) const { return {x - p.x, y - p.y}; }
  Point operator*(Point b) const {
    return {x * b.x - y * b.y, x * b.y + y * b.x};
  }

  // Operaciones de comparacion para enteros
  bool operator<(Point p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(Point p) const { return tie(x, y) == tie(p.x, p.y); }

  // Operaciones Punto - Numero
  Point operator*(T d) const { return {x * d, y * d}; }

  T sq() { return x * x + y * y; }
  double norm() { return sqrt(sq()); }
  Point perp() { return {-y, x}; }
  T dot(Point p) { return x * p.x + y * p.y; }
  T cross(Point p) const { return x * p.y - y * p.x; }
  T cross(Point a, Point b) const { return (a - *this).cross(b - *this); }
};

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
  if (orient(p[0], p[1], p[2]) < 0) reverse(ALL(p));
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
    i += cross >= 0;
    j += cross <= 0;
  }
  return r;
}

int sgn(T x) { return (T(0) < x) - (x < T(0)); }

bool inDisk(Point a, Point b, Point p) { return (a - p).dot(b - p) <= 0; }

// Retorna si el punto P se encuentra en el segmento de puntos S a E
bool onSegment(Point a, Point b, Point p) {
  return a.cross(b, p) == 0 && inDisk(a, b, p);
}

bool inPolygonCH(vector<Point>& l, Point p, bool strict = false) {
  int a = 1, b = SZ(l) - 1, r = !strict;
  if (SZ(l) < 3) return r && onSegment(l[0], l.back(), p);
  if (orient(l[0], l[a], l[b]) > 0) swap(a, b);
  if (orient(l[0], l[a], p) >= r || orient(l[0], l[b], p) <= -r) return false;
  while (abs(a - b) > 1) {
    int c = (a + b) / 2;
    (orient(l[0], l[c], p) > 0 ? b : a) = c;
  }
  return sgn(l[a].cross(l[b], p)) < r;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<Point> p(n);
  FOR(i, 0, n) cin >> p[i].x >> p[i].y;

  int m;
  cin >> m;
  vector<Point> q(m);
  FOR(i, 0, m) cin >> q[i].x >> q[i].y;

  vector<Point> pcq = minkowski_sum(p, q);

  vector<Point> dobp(n), minp(n);
  FOR(i, 0, n) {
    dobp[i] = p[i] * 2;
    minp[i] = p[i] * -1;
  }

  vector<Point> dobq(m), minq(m);
  FOR(i, 0, m) {
    dobq[i] = q[i] * 2;
    minq[i] = q[i] * -1;
  }
  vector<Point> cpq = minkowski_sum(dobp, minq);
  vector<Point> pqc = minkowski_sum(minp, dobq);

  int que;
  cin >> que;
  while (que--) {
    Point pt;
    cin >> pt.x >> pt.y;
    if (inPolygonCH(pcq, pt * 2) || inPolygonCH(cpq, pt) ||
        inPolygonCH(pqc, pt))
      cout << "Y";
    else
      cout << "N";
  }

  return 0;
}