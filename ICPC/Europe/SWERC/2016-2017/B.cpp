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
  T x, y, z;

  // Operaciones Punto - Punto
  Point operator+(Point p) const { return {x + p.x, y + p.y}; }
  Point operator-(Point p) const { return {x - p.x, y - p.y}; }
  Point operator*(Point b) const { return {x * b.x - y * b.y, x * b.y + y * b.x}; }

  // Operaciones Punto - Numero
  Point operator*(T d) const { return {x * d, y * d}; }
  Point operator/(T d) const { return {x / d, y / d}; }  // Solo para punto flotante

  // Operaciones de comparacion para enteros
  bool operator<(Point p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(Point p) const { return tie(x, y) == tie(p.x, p.y); }

  T sq() { return x * x + y * y; }
  double norm() { return sqrt(sq()); }
  Point unit() { return *this / norm(); }

  // Operaciones generales:
  Point translate(Point v) { return *this + v; }
  Point scale(Point c, double factor) { return c + (*this - c) * factor; }
  Point perp() { return {-y, x}; }

  T dot(Point p) { return x * p.x + y * p.y; }
  T cross(Point p) const { return x * p.y - y * p.x; }
  T cross(Point a, Point b) const { return (a - *this).cross(b - *this); }

  friend ostream& operator<<(ostream& os, Point p) {
    return os << "(" << p.x << "," << p.y << "," << p.z << ")";
  }
};
int half(Point p) { return p.y > 0 || (p.y == 0 && p.x < 0); }

void polarSort(vector<Point>& v) {
  sort(ALL(v), [](Point v, Point w) {
    return make_tuple(half(v), 0) < make_tuple(half(w), v.cross(w));
  });
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n, same = 0;
  cin >> n;
  ll x0, y0;
  cin >> x0 >> y0;
  vector<Point> pts;
  FOR(i, 0, n - 1) {
    ll x, y;
    cin >> x >> y;
    if (x == x0 && y == y0) {
      same++;
      continue;
    }
    pts.pb({x - x0, y - y0, 1});
    pts.pb({x0 - x, y0 - y, 0});
  }
  if (!SZ(pts)) {
    cout << 1 << " " << same + 1 << ENDL;
    return 0;
  }
  polarSort(pts);
  vector<Point> pts2;
  for (int i = 0, j = 0; i < SZ(pts); i = j) {
    int sum = 0;
    for (j = i; j < SZ(pts) && pts[i].cross(pts[j]) == 0 && pts[j].dot(pts[i]) > 0; j++) {
      sum += pts[j].z;
    }
    pts2.pb({pts[i].x, pts[i].y, sum});
  }

  int m = SZ(pts2);
  FOR(i, 0, m) {
    pts2.pb(pts2[i]);
  }
  vi prefix(m + m + 5, 0);
  FOR(i, 1, m + m + 1) {
    prefix[i] = prefix[i - 1] + pts2[i - 1].z;
  }
  ll ansmin = 3e8;
  ll ansmax = 0;
  for (int i = 0, j = 0; i < m; i++) {
    if (j < i) j = i;
    while (j + 1 < i + m && pts2[i].cross(pts2[j + 1]) >= 0) j++;
    if (pts2[i].x < 0 || pts2[i].y > 0) continue;

    ll inarea = prefix[j + 1] - prefix[i];
    ll online = pts2[i].z;
    if (i < j && pts2[i].cross(pts2[j]) == 0) online += pts2[j].z;
    inarea -= online;
    online += same;
    ansmin = min(ansmin, inarea + 1);
    ansmax = max(ansmax, inarea + online + 1);
  }
  /*if (ansmax == 0) {
    cout << n << " " << n << ENDL;
    return 0;
  }*/
  cout << ansmin << " " << ansmax << ENDL;

  return 0;
}