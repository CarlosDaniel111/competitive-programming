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

using ld = long double;

template<class T> struct Point3D {
	typedef Point3D P;
	typedef const P& R;
	T x, y, z;
	explicit Point3D(T x=0, T y=0, T z=0) : x(x), y(y), z(z) {}
	bool operator<(R p) const {
		return tie(x, y, z) < tie(p.x, p.y, p.z); }
	bool operator==(R p) const {
		return tie(x, y, z) == tie(p.x, p.y, p.z); }
	P operator+(R p) const { return P(x+p.x, y+p.y, z+p.z); }
	P operator-(R p) const { return P(x-p.x, y-p.y, z-p.z); }
	P operator*(T d) const { return P(x*d, y*d, z*d); }
	P operator/(T d) const { return P(x/d, y/d, z/d); }
	T dot(R p) const { return x*p.x + y*p.y + z*p.z; }
	P cross(R p) const {
		return P(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x);
	}
	T dist2() const { return x*x + y*y + z*z; }
	ld dist() const { return sqrt((ld)dist2()); }
	//Azimuthal angle (longitude) to x-axis in interval [-pi, pi]
	ld phi() const { return atan2(y, x); } 
	//Zenith angle (latitude) to the z-axis in interval [0, pi]
	ld theta() const { return atan2(sqrt(x*x+y*y),z); }
	P unit() const { return *this/(T)dist(); } //makes dist()=1
	//returns unit vector normal to *this and p
	P normal(P p) const { return cross(p).unit(); }
	//returns point rotated 'angle' radians ccw around axis
	P rotate(ld angle, P axis) const {
		ld s = sin(angle), c = cos(angle); P u = axis.unit();
		return u*dot(u)*(1-c) + (*this)*c - cross(u)*s;
	}
  void print(){
    cout << x << " " << y << " " << z << ENDL;
  }
};

typedef Point3D<ld> P3;

struct PR {
	void ins(int x) { (a == -1 ? a : b) = x; }
	void rem(int x) { (a == x ? a : b) = -1; }
	int cnt() { return (a != -1) + (b != -1); }
	int a, b;
};

struct F { P3 q; int a, b, c; };

vector<F> hull3d(const vector<P3>& A) {
	vector<vector<PR>> E(SZ(A), vector<PR>(SZ(A), {-1, -1}));
#define E(x,y) E[f.x][f.y]
	vector<F> FS;
	auto mf = [&](int i, int j, int k, int l) {
		P3 q = (A[j] - A[i]).cross((A[k] - A[i]));
		if (q.dot(A[l]) > q.dot(A[i]))
			q = q * -1;
		F f{q, i, j, k};
		E(a,b).ins(k); E(a,c).ins(j); E(b,c).ins(i);
		FS.push_back(f);
	};
	FOR(i,0,4) FOR(j,i+1,4) FOR(k,j+1,4)
		mf(i, j, k, 6 - i - j - k);

	FOR(i,4,SZ(A)) {
		FOR(j,0,SZ(FS)) {
			F f = FS[j];
			if(f.q.dot(A[i]) > f.q.dot(A[f.a])) {
				E(a,b).rem(f.c);
				E(a,c).rem(f.b);
				E(b,c).rem(f.a);
				swap(FS[j--], FS.back());
				FS.pop_back();
			}
		}
		int nw = SZ(FS);
		FOR(j,0,nw) {
			F f = FS[j];
#define C(a, b, c) if (E(a,b).cnt() != 2) mf(f.a, f.b, i, f.c);
			C(a, b, c); C(a, c, b); C(b, c, a);
		}
	}
	for (F& it : FS) if ((A[it.b] - A[it.a]).cross(
		A[it.c] - A[it.a]).dot(it.q) <= 0) swap(it.c, it.b);
	return FS;
};


typedef ld T;

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


  T sq() { return x * x + y * y; }
  ld norm() { return sqrt(sq()); }
  Point unit() { return *this / norm(); }

  // Operaciones generales:
  Point translate(Point v) { return *this + v; }
  Point scale(Point c, ld factor) { return c + (*this - c) * factor; }
  Point rotate(ld ang) { return {x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang)}; }
  Point rot_around(ld ang, Point c) { return c + (*this - c).rotate(ang); }
  Point perp() { return {-y, x}; }

  T dot(Point p) { return x * p.x + y * p.y; }
  T cross(Point p) const { return x * p.y - y * p.x; }
  T cross(Point a, Point b) const { return (a - *this).cross(b - *this); }
  ld angle() const { return atan2(y, x); }

  friend ostream& operator<<(ostream& os, Point p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};

Point circumCenter(const Point& A, const Point& B, const Point& C) {
  Point b = C - A, c = B - A;
  assert(b.cross(c) != 0);
  return A + (b * c.sq() - c * b.sq()).perp() / b.cross(c) / 2;
}

pair<Point, ld> mec(vector<Point> pts) {
  shuffle(ALL(pts), mt19937(time(0)));
  Point o = pts[0];
  ld r = 0, EPS = 1 + 1e-8;
  FOR(i, 0, SZ(pts)) if ((o - pts[i]).norm() > r * EPS) {
    o = pts[i], r = 0;
    FOR(j, 0, i) if ((o - pts[j]).norm() > r * EPS) {
      o = (pts[i] + pts[j]) / 2;
      r = (o - pts[i]).norm();
      FOR(k, 0, j) if ((o - pts[k]).norm() > r * EPS) {
        o = circumCenter(pts[i], pts[j], pts[k]);
        r = (o - pts[i]).norm();
      }
    }
  }
  return {o, r};
}

ld PI = acos(-1);

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<P3> pts(n);
  FOR(i,0,n){
    cin >> pts[i].x >> pts[i].y >> pts[i].z;
  }
  vector<F> ch = hull3d(pts);

  ld ans = 1e30;
  
  for(auto face:ch){
    P3 pta = pts[face.a],ptb = pts[face.b],ptc = pts[face.c];
    P3 q = (face.q*-1).unit();
    P3 dx = (ptb-pta).unit();
    P3 dy = dx.normal(q);
    ld mxh=0,mnh=1e30;

    FOR(i,0,n){
      ld dToPlane = pts[i].dot(q);
      mxh = max(dToPlane,mxh);
      mnh = min(dToPlane,mnh);
    }

    vector<Point> pts2d(n);
    FOR(i,0,n){
      pts2d[i] = {pts[i].dot(dx),pts[i].dot(dy)};
    }

    pair<Point, ld> circulo = mec(pts2d);
    ld h = abs(mxh - mnh);
    ld curr = PI * (circulo.second*circulo.second)*h;
    ans = min(ans,curr);
  }

    cout << setprecision(12) << fixed;
  cout << ans << ENDL;


  return 0;
}