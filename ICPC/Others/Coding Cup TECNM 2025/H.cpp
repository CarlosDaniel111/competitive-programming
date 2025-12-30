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

struct Point {
  ll x, y;
};

struct DSU {
  vector<int> e;
  void init(int n) { e.assign(n, -1); }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool join(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

vector<tuple<ll, int, int>> manhattan_mst_edges(vector<Point> ps) {
  vector<int> ids(ps.size());
  iota(ids.begin(), ids.end(), 0);
  vector<tuple<ll, int, int>> edges;
  for (int rot = 0; rot < 4; rot++) {
    sort(ids.begin(), ids.end(), [&](int i, int j) {
      return (ps[i].x + ps[i].y) < (ps[j].x + ps[j].y);
    });
    map<int, int, greater<int>> active;
    for (auto i : ids) {
      for (auto it = active.lower_bound(ps[i].x); it != active.end();
           active.erase(it++)) {
        int j = it->second;
        if (ps[i].x - ps[i].y > ps[j].x - ps[j].y) break;
        edges.push_back({(ps[i].x - ps[j].x) + (ps[i].y - ps[j].y), i, j});
      }
      active[ps[i].x] = i;
    }
    for (auto& p : ps) {
      if (rot & 1)
        p.x *= -1;
      else
        swap(p.x, p.y);
    }
  }
  return edges;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<Point> pts(n);
  for (int i = 0; i < n; ++i) {
    cin >> pts[i].x >> pts[i].y;
  }

  vector<tuple<ll, int, int>> edges = manhattan_mst_edges(pts);

  sort(edges.begin(), edges.end());

  DSU dsu;
  dsu.init(n);
  ll ans = 0;
  for (auto& [w, u, v] : edges) {
    if (dsu.join(u, v)) ans += w;
  }

  cout << ans << ENDL;
  return 0;
}