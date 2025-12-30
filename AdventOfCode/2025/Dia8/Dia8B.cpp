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

vector<string> split(string str, char pattern) {
  int posInit = 0;
  int posFound = 0;
  string splitted;
  vector<string> results;

  while (posFound >= 0) {
    posFound = str.find(pattern, posInit);
    splitted = str.substr(posInit, posFound - posInit);
    posInit = posFound + 1;
    results.push_back(splitted);
  }

  return results;
}

struct Point {
  ll x, y, z;
};

ll dist(Point a, Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) +
         (a.z - b.z) * (a.z - b.z);
}

struct DSU {
  vector<int> e;
  void init(int n) { e = vi(n, -1); }
  int size(int x) { return -e[get(x)]; }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ifstream file(
      "/Users/CarlosBeltran/Documents/ICPC/competitive-programming/"
      "AdventofCode/2025/Dia8/input.txt");

  string line;
  vector<Point> pts;
  while (getline(file, line)) {
    vector<string> pt = split(line, ',');
    pts.pb({stoll(pt[0]), stoll(pt[1]), stoll(pt[2])});
  }
  int n = SZ(pts);
  vector<tuple<ll, int, int>> a;
  FOR(i, 0, n) {
    FOR(j, i + 1, n) { a.pb({dist(pts[i], pts[j]), i, j}); }
  }
  sort(ALL(a));
  DSU dsu;
  dsu.init(n);
  FOR(k, 0, SZ(a)) {
    auto [d, i, j] = a[k];
    dsu.join(i, j);
    if (dsu.size(i) == n) {
      cout << pts[i].x * pts[j].x << ENDL;
      return 0;
    }
  }

  return 0;
}