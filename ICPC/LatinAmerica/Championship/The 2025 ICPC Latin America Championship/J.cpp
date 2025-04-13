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

const double PI = acos(-1.0);
inline double RAD_to_DEG(double r) { return (r * 180.0 / PI); }
typedef long long T;

constexpr long double EPS = 1e-9;

struct P3 {
  T x, y, z;

  // Operaciones Punto - Punto
  P3 operator+(P3 p) const { return {x + p.x, y + p.y, z + p.z}; }
  P3 operator-(P3 p) const { return {x - p.x, y - p.y, z - p.z}; }

  // Operacion Punto - Numero
  P3 operator*(T d) const { return {x * d, y * d, z * d}; }
  P3 operator/(T d) const { return {x / d, y / d, z / d}; }

  // Operaciones de comparacion para enteros
  bool operator<(P3 p) const { return tie(x, y, z) < tie(p.x, p.y, p.z); }
  bool operator==(P3 p) const { return tie(x, y, z) == tie(p.x, p.y, p.z); }

  // Operaciones generales
  T sq() { return x * x + y * y + z * z; }
  double norm() { return sqrt(sq()); }
  P3 unit() { return *this / norm(); }
  T dot(P3 p) { return x * p.x + y * p.y + z * p.z; }
  P3 cross(P3 p) {
    return {y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x};
  }
  P3 cross(P3 a, P3 b) { return (a - *this).cross(b - *this); }

  friend ostream& operator<<(ostream& os, P3 p) {
    return os << "(" << p.x << "," << p.y << "," << p.z << ")";
  }
};

double angle(P3 v, P3 w) {
  double cosTheta = v.dot(w) / v.norm() / w.norm();
  return acos(cosTheta);
}

struct PR {
  void ins(int x) { (a == -1 ? a : b) = x; }
  void rem(int x) { (a == x ? a : b) = -1; }
  int cnt() { return (a != -1) + (b != -1); }
  int a, b;
};

struct F {
  P3 q;
  int a, b, c;
};

vector<F> hull3d(const vector<P3>& A) {
  assert(SZ(A) >= 4);
  vector<vector<PR>> E(SZ(A), vector<PR>(SZ(A), {-1, -1}));
#define E(x, y) E[f.x][f.y]
  vector<F> FS;
  auto mf = [&](int i, int j, int k, int l) {
    P3 q = (A[j] - A[i]).cross((A[k] - A[i]));
    if (q.dot(A[l]) > q.dot(A[i])) q = q * -1;
    F f{q, i, j, k};
    E(a, b).ins(k);
    E(a, c).ins(j);
    E(b, c).ins(i);
    FS.push_back(f);
  };
  FOR(i, 0, 4) FOR(j, i + 1, 4) FOR(k, j + 1, 4) mf(i, j, k, 6 - i - j - k);

  FOR(i, 4, SZ(A)) {
    FOR(j, 0, SZ(FS)) {
      F f = FS[j];
      if (f.q.dot(A[i]) > f.q.dot(A[f.a])) {
        E(a, b).rem(f.c);
        E(a, c).rem(f.b);
        E(b, c).rem(f.a);
        swap(FS[j--], FS.back());
        FS.pop_back();
      }
    }
    int nw = SZ(FS);
    FOR(j, 0, nw) {
      F f = FS[j];
#define C(a, b, c) \
  if (E(a, b).cnt() != 2) mf(f.a, f.b, i, f.c);
      C(a, b, c);
      C(a, c, b);
      C(b, c, a);
    }
  }
  for (F& it : FS)
    if ((A[it.b] - A[it.a]).cross(A[it.c] - A[it.a]).dot(it.q) <= 0)
      swap(it.c, it.b);
  return FS;
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<P3> pts(n);
  FOR(i, 0, n) cin >> pts[i].x >> pts[i].y >> pts[i].z;

  cout << setprecision(12) << fixed;

  if (n <= 3) {
    cout << 90 << ENDL;
    return 0;
  }

  vector<F> faces = hull3d(pts);
  double ans = 1e9;
  for (auto face : faces) {
    double curr = -1e9;
    FOR(i, 0, n) { curr = max(curr, angle(face.q, pts[i])); }
    cout << 180.0 - RAD_to_DEG(curr) << ENDL;
    ans = min(ans, curr);
    curr = -1e9;
    face.q = face.q * -1;
    FOR(i, 0, n) { curr = max(curr, angle(face.q, pts[i])); }
    ans = min(ans, curr);
  }
  // ans = acos(max((long double)-1.0, min((long double)1.0, ans)));
  cout << 180.0 - RAD_to_DEG(ans) << ENDL;

  return 0;
}