#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ENDL '\n'

using ll = long long;

struct Point {
  ll x, y;
};

ll dist(Point a, Point b) {
  ll dx = a.x - b.x, dy = a.y - b.y;
  return dx * dx + dy * dy;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<Point> pts(n);
  FOR(i, 0, n) cin >> pts[i].x >> pts[i].y;
  int a = 1;
  FOR(i, 2, n) {
    if (dist(pts[0], pts[a]) < dist(pts[0], pts[i])) a = i;
  }
  vector<pair<ll, int>> d(n);
  FOR(i, 0, n) { d[i] = {dist(pts[a], pts[i]), i}; }
  sort(d.begin(), d.end());
  double ans = 0.0;
  FOR(i, 1, n) { ans += sqrt(dist(pts[d[i - 1].second], pts[d[i].second])); }
  cout << setprecision(13) << fixed;
  cout << ans << '\n';

  return 0;
}