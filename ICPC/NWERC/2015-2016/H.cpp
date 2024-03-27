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
  double angle() const { return atan2(y, x); }

  friend ostream& operator<<(ostream& os, Point p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};

T orient(Point a, Point b, Point c) { return a.cross(b, c); }

bool properInter(Point a, Point b, Point c, Point d, Point& p) {
  double oa = orient(c, d, a),
         ob = orient(c, d, b),
         oc = orient(a, b, c),
         od = orient(a, b, d);
  if (oa * ob < 0 && oc * od < 0) {
    p = (a * ob - b * oa) / (ob - oa);
    return true;
  }
  return false;
}

// Retorna si el Punto P se encuentra dentro del circulo entre A y B
bool inDisk(Point a, Point b, Point p) { return (a - p).dot(b - p) <= EPS; }

// Retorna si el punto P se encuentra en el segmento de puntos S a E
bool onSegment(Point a, Point b, Point p) {
  return abs(a.cross(b, p)) < EPS && inDisk(a, b, p);
}

bool segInter(Point a, Point b, Point c, Point d, Point& out) {
  Point p;
  if (properInter(a, b, c, d, out)) return true;
  set<Point> s;
  if (onSegment(c, d, a)) {
    out = a;
    return true;
  }
  if (onSegment(c, d, b)) {
    out = b;
    return true;
  }
  if (onSegment(a, b, c)) {
    out = c;
    return true;
  }
  if (onSegment(a, b, d)) {
    out = d;
    return true;
  }
  return false;
}

double dist(Point p1, Point p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }

int n, ans;
vector<pair<Point, Point>> l;
Point hole;
vi id;

bool check() {
  int tot = SZ(id);
  Point now = hole;
  vi used(n, 0);
  ROF(i, tot, 0) {
    if (l[id[i]].first.x == l[id[i]].second.x) {
      now.x = l[id[i]].first.x * 2 - now.x;
    } else {
      now.y = l[id[i]].first.y * 2 - now.y;
    }
  }
  Point s{0, 0};
  FOR(i, 0, tot) {
    pair<Point, Point> ff = {s, now};
    Point res{0, 0};
    if (!segInter(s, now, l[id[i]].first, l[id[i]].second, res)) return 0;
    used[id[i]] = 1;
    FOR(j, 0, n) {
      if (used[j]) continue;
      Point aux{0, 0};
      if (!segInter(s, now, l[j].first, l[j].second, aux)) continue;
      if (dist(s, res) - dist(s, aux) > -EPS) return 0;
    }
    s = res;
    if (l[id[i]].first.x == l[id[i]].second.x) {
      now.x = l[id[i]].first.x * 2 - now.x;
    } else {
      now.y = l[id[i]].first.y * 2 - now.y;
    }
  }

  FOR(i, 0, n) {
    if (used[i]) continue;
    Point aux{0, 0};
    if (segInter(s, now, l[i].first, l[i].second, aux)) return 0;
  }
  return 1;
}

int solve(int mask) {
  id.clear();
  FOR(i, 0, n) {
    if ((mask >> i) & 1) {
      id.pb(i);
    }
  }
  if (ans >= SZ(id))
    return ans;
  do {
    if (check())
      return SZ(id);
  } while (next_permutation(ALL(id)));
  return -1;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n;
  cin >> hole.x >> hole.y;
  l.resize(n);
  FOR(i, 0, n) {
    cin >> l[i].first.x >> l[i].first.y >> l[i].second.x >> l[i].second.y;
  }

  ans = -1;
  FOR(i, 0, 1 << n) {
    ans = max(ans, solve(i));
  }
  if (ans == -1) {
    cout << "impossible" << ENDL;
    return 0;
  }
  cout << ans << ENDL;

  return 0;
}