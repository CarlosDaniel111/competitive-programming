#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = a - 1; i >= b; i--)
#define ENDL '\n'
#define __                      \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);

constexpr double EPS = 1e-9;
const double PI = acos(-1.0);

typedef double T;
struct Point {
  T x, y;

  friend ostream& operator<<(ostream& os, Point p) {
    return os << p.x << " " << p.y;
  }
};

Point circlePoint(Point c, double r, double ang) {
  return Point{c.x + cos(ang) * r, c.y + sin(ang) * r};
}

vector<Point> ans;
vector<vi> g;

int cnt, n;

void dfs(int u, int p = -1) {
  FOR(i, 0, SZ(g[u])) {
    if (g[u][i] == p) continue;
    int v = g[u][i];
    ans[v] = circlePoint(ans[u], 1, (cnt * PI) / n);
    cnt++;
    dfs(v, u);
  }
}

signed main() {
  __

          cin >>
      n;
  g.assign(n, vi());
  ans.resize(n);
  FOR(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  dfs(0);
  cout << setprecision(12) << fixed;
  FOR(i, 0, n) {
    cout << ans[i] << ENDL;
  }

  return 0;
}