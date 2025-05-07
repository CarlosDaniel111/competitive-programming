#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <assert.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using ld = long double;
using T = ld;

#define SZ(x) ((int)x.size())

constexpr T EPS = 1e-7;
const T PI = acos(-1.0l);

struct p3 {
  T x = 0, y = 0, z = 0;
  p3 operator+(p3 p) const {
    return {x + p.x, y + p.y, z + p.z};
  }
  p3 operator-(p3 p) const {
    return {x - p.x, y - p.y, z - p.z};
  }
  p3 operator*(T d) const {
    return {x * d, y * d, z * d};
  }
  p3 operator/(T d) const {
    return {x / d, y / d, z / d};
  }
  p3 operator*(p3 w) const {
    return {
      y * w.z - z * w.y,
      z * w.x - x * w.z,
      x * w.y - y * w.x
    };
  }
  T dot(p3 w) {
    return x * w.x + y * w.y + z * w.z;
  }
  T sq() {
    return dot(*this);
  }
  ld abs() {
    return sqrt(sq());
  };
  p3 unit() {
    return *this / abs();
  }
  void print(){
    cout << x << ' ' << y << ' ' << z << '\n';
  }
};

ld angle(p3 v, p3 w) {
  ld cosTheta = v.dot(w) / v.abs() / w.abs();
  return acos(max(-1.0l, min(-1.0l, cosTheta)));
}

ld dist(p3 v, p3 w) {
  return (v-w).abs();
}

struct line3d {
  p3 d, o;
  line3d(p3 p, p3 q) : d(q - p) { o = p; }
  ld sqDist(p3 p) {
    return (d * (p - o)).sq() / d.sq();
  }
  ld dist(p3 p) {
    return sqrt(sqDist(p));
  }
  p3 proj(p3 p) {
    return o + d*(d.dot(p - o)) / d.sq();
  }
};

int sphereLine(p3 o, ld r, line3d l, pair<p3, p3> &out) {
  ld h2 = r * r - l.sqDist(o);
  if (h2 < 0) return 0;
  p3 p = l.proj(o);
  p3 h = l.d*sqrt(h2) / l.d.abs();
  out = {p - h, p + h};
  return 1 + (h2 > 0);
}

bool areCollinear(p3 a,p3 b,p3 c){
  line3d line(a,b);
  return (line.sqDist(c) < EPS &&  line.sqDist(c) > -EPS);
}

struct pt {
  T x = 0, y = 0;
  pt operator+(pt p) const { return {x + p.x, y + p.y}; }
  pt operator-(pt p) const { return {x - p.x, y - p.y}; }
  pt operator*(T d) const { return {x * d, y * d}; }
  pt operator/(T d) const { return {x / d, y / d}; }
  bool operator==(pt p) const {
    return abs(x - p.x) <= EPS && abs(y - p.y) <= EPS;
  }
  bool operator!=(pt p) const {
    return !((*this) == p);
  }

  T sq() { return x * x + y * y; }
  pt perp() { return {-y, x}; }
  T norm() { return sqrt(sq()); }
  T dot(pt p) {
    return x * p.x + y * p.y;
  }
  T cross(pt p) const {
    return x * p.y - y * p.x;
  }
  T cross(pt a, pt b) const {
    return (a - *this).cross(b - *this);
  }
  void print(){
    cout << '(' << x << ", " << y << ')' << '\n';
  }
};

T dist(pt p1, pt p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y);
}

double acos1(double x)
    {
        if(x > 1)
          x = 1;
        if(x < -1)
          x = -1;
        return acos(x);
    }

T angle(pt v, pt w) {
  ld cosTheta = v.dot(w) / v.norm() / w.norm();
  return acos1(cosTheta);
}

T angle(pt o, pt a, pt b) {
  return angle(a - o, b - o);
}

T distOnCircle(pt o, pt a, pt b, T r) {
  return r * angle(o, a, b);
}

struct coords {
  p3 o, dx, dy, dz;
  coords(p3 p, p3 q, p3 r) {
    o = p;
    dx = (q - p).unit();
    dz = (dx * (r - p)).unit();
    dy = dz * dx;
  }
  pt pos2d(p3 p) {
    return {(p - o).dot(dx), (p - o).dot(dy)}; 
  }
};

int tangents(pt o1, ld r1, pt o2, ld r2, bool inner, vector<pair<pt, pt>> &out) {
  if (inner) r2 = -r2;
  pt d = o2 - o1;
  ld dr = r1 - r2, d2 = d.sq(), h2 = d2 - dr * dr;
  if (d2 == 0 || h2 < 0) {
    //assert(h2 != 0);
    return 0;
  }
  for (ld sign : {-1, 1}) {
    pt v = (d * dr + d.perp() * sqrt(h2) * sign) / d2;
    out.push_back({o1 + v * r1, o2 + v * r2});
  }
  return 1 + (h2 > 0);
}

T calc(pt c, ld r, pt a, pt ta, pt b, pt tb) {
  T ans = dist(a, ta) + dist(b, tb);
  ans += distOnCircle(c, ta, tb, r);
  return ans;
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  p3 a, b, c;
  cin >> a.x >> a.y >> a.z;
  cin >> b.x >> b.y >> b.z;
  cin >> c.x >> c.y >> c.z;
  ld r;
  cin >> r;

  line3d l_ab(a, b);
  
  pair<p3, p3> inter;
  int cnt = sphereLine(c, r, l_ab, inter);
  
  if (cnt < 2) {
    printf("%.10Lf\n", dist(a, b));
    return 0;
  }
  
  pt a2, b2, c2;
  
  if (areCollinear(a, b, c)) {
    ld da = a.abs(), db = b.abs(), dc = c.abs();
    a2 = {0, da}, b2 = {0, db}, c2 = {0, dc};
  }
  else {
    coords mapper(a, b, c);
    a2 = mapper.pos2d(a);
    b2 = mapper.pos2d(b);
    c2 = mapper.pos2d(c);
  }

  vector<pair<pt, pt>> tan_a, tan_b;
  tangents(c2, r, a2, 0, 0, tan_a);
  tangents(c2, r, b2, 0, 0, tan_b);

  // assert(!tan_a.empty() && !tan_b.empty());

  ld ans = 1e9;

  for (int i = 0; i < SZ(tan_a); i++) {
    for (int j = 0; j < SZ(tan_b); j++) {
      ans = min(ans, calc(c2, r, a2, tan_a[i].first, b2, tan_b[j].first));
    }
  }

  // cout << ans << '\n';
  printf("%.10Lf\n", ans);

  return 0;
}