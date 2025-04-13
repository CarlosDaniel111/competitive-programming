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

struct Point {
  long long x, y, z;
  Point(long long x = 0, long long y = 0, long long z = 0) : x(x), y(y), z(z) {}
  Point operator-(const Point& p) const {
    return Point(x - p.x, y - p.y, z - p.z);
  }
  Point cross(const Point& p) const {
    return Point(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
  }
  long long dot(const Point& p) const { return x * p.x + y * p.y + z * p.z; }
  double norm() const { return sqrt(x * x + y * y + z * z); }
  Point unit() const {
    double n = norm();
    return Point(x / n, y / n, z / n);
  }
};

struct Face {
  Point normal;
  vector<int> vertices;
};

vector<Point> points;
vector<Face> convexHull;

void computeConvexHull() {
  int N = points.size();
  if (N < 4) return;

  vector<tuple<int, int, int>> faces;

  auto addFace = [&](int a, int b, int c) {
    Point normal = (points[b] - points[a]).cross(points[c] - points[a]);
    faces.emplace_back(a, b, c);
    convexHull.push_back({normal, {a, b, c}});
  };

  addFace(0, 1, 2);
  addFace(0, 1, 3);
  addFace(0, 2, 3);
  addFace(1, 2, 3);

  for (int i = 4; i < N; i++) {
    vector<tuple<int, int, int>> newFaces;
    vector<Face> updatedHull;
    for (auto [a, b, c] : faces) {
      Point normal = (points[b] - points[a]).cross(points[c] - points[a]);
      if (normal.dot(points[i] - points[a]) > 0) {
        newFaces.push_back({a, b, i});
        newFaces.push_back({b, c, i});
        newFaces.push_back({c, a, i});
      } else {
        updatedHull.push_back({normal, {a, b, c}});
      }
    }
    faces = newFaces;
    convexHull = updatedHull;
    for (auto [a, b, c] : newFaces) {
      addFace(a, b, c);
    }
  }
}

double findOptimalAngle() {
  long long bestP = 1;
  for (const auto& face : convexHull) {
    for (int sign : {-1, 1}) {
      Point normal = face.normal;
      normal = Point(sign * normal.x, sign * normal.y, sign * normal.z);
      long long maxDot = -1;
      for (const auto& p : points) {
        maxDot = max(maxDot, normal.dot(p));
      }
      bestP = min(bestP, maxDot);
    }
  }
  cout << bestP << ENDL;
  if (bestP < 0) return PI / 2;
  return acos((double)bestP);
}

int main() {
  int N;
  cin >> N;
  points.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> points[i].x >> points[i].y >> points[i].z;
  }

  if (N <= 3) {
    cout << 90 << ENDL;
    return 0;
  }

  computeConvexHull();
  double optimalAngle = findOptimalAngle();
  cout << setprecision(12) << fixed;
  cout << RAD_to_DEG(optimalAngle) << ENDL;

  return 0;
}
