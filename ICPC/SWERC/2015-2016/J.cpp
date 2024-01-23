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

typedef ll T;

int sgn(T x) { return (T(0) < x) - (x < T(0)); }

struct Point {
  T x, y;

  // Operaciones Punto - Punto
  Point operator+(Point p) const { return {x + p.x, y + p.y}; }
  Point operator-(Point p) const { return {x - p.x, y - p.y}; }
  Point operator*(Point b) const { return {x * b.x - y * b.y, x * b.y + y * b.x}; }

  // Operaciones de comparacion para enteros
  bool operator<(Point p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(Point p) const { return tie(x, y) == tie(p.x, p.y); }

  T sq() { return x * x + y * y; }
  double norm() { return sqrt(sq()); }

  T dot(Point p) { return x * p.x + y * p.y; }
  T cross(Point p) const { return x * p.y - y * p.x; }
  T cross(Point a, Point b) const { return (a - *this).cross(b - *this); }
};

T orient(Point a, Point b, Point c) { return a.cross(b, c); }

bool inDisk(Point a, Point b, Point p) { return (a - p).dot(b - p) <= 0; }

// Retorna si el punto P se encuentra en el segmento de puntos S a E
bool onSegment(Point a, Point b, Point p) {
  return a.cross(b, p) == 0 && inDisk(a, b, p);
}

vector<Point> convexHull(vector<Point> pts) {
  if (SZ(pts) <= 1) return pts;
  sort(ALL(pts));
  vector<Point> h(SZ(pts) + 1);
  int s = 0, t = 0;
  for (int it = 2; it--; s = --t, reverse(ALL(pts)))
    for (Point p : pts) {
      while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0) t--;  // quitar = si se incluye colineares
      h[t++] = p;
    }
  return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

bool inPolygonCH(vector<Point>& l, Point p, bool strict = true) {
  int a = 1, b = SZ(l) - 1, r = !strict;
  if (SZ(l) < 3) return r && onSegment(l[0], l.back(), p);
  if (orient(l[0], l[a], l[b]) > 0) swap(a, b);
  if (orient(l[0], l[a], p) >= r || orient(l[0], l[b], p) <= -r)
    return false;
  while (abs(a - b) > 1) {
    int c = (a + b) / 2;
    (orient(l[0], l[c], p) > 0 ? b : a) = c;
  }
  return sgn(l[a].cross(l[b], p)) < r;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int L;
  cin >> L;
  vector<Point> pts(L);
  FOR(i, 0, L) {
    ll x, y;
    cin >> x >> y;
    pts[i] = {x, y};
  }
  vector<Point> convex = convexHull(pts);

  int S, ans = 0;
  cin >> S;
  FOR(i, 0, S) {
    ll x, y;
    cin >> x >> y;
    if (inPolygonCH(convex, Point{x, y}, false)) {
      ans++;
    }
  }
  cout << ans << ENDL;

  return 0;
}