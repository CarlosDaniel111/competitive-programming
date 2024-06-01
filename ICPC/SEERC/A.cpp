#include <bits/stdc++.h>
using namespace std;

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

vector<Point> pts;
vi vis;
int n;

void ponerCuadrado(Point up, Point down, int val) {
  FOR(i, 0, n) {
    if (pts[i].x >= up.x && pts[i].y <= up.y && pts[i].x <= down.x && pts[i].y >= down.y) {
      vis[i] += val;
    }
  }
}

bool solve(int x, int cnt) {
  ll mnx = 1e9 + 5, mny = 1e9 + 5, mxx = -1, mxy = -1;
  int cnt2 = 0;
  FOR(i, 0, n) {
    if (vis[i]) continue;
    cnt2++;
    mnx = min(mnx, pts[i].x);
    mxx = max(mxx, pts[i].x);
    mny = min(mny, pts[i].y);
    mxy = max(mxy, pts[i].y);
  }

  if (cnt2 == 0) return true;
  if (cnt == 2) {
    if (mxx - mnx > x) return 0;
    if (mxy - mny > x) return 0;
    return true;
  }

  // UP-LEFT
  ponerCuadrado(Point{mnx, mxy}, Point{mnx + x, mxy - x}, 1);
  if (solve(x, cnt + 1)) return true;
  ponerCuadrado(Point{mnx, mxy}, Point{mnx + x, mxy - x}, -1);

  // UP-RIGHT
  ponerCuadrado(Point{mxx - x, mxy}, Point{mxx, mxy - x}, 1);
  if (solve(x, cnt + 1)) return true;
  ponerCuadrado(Point{mxx - x, mxy}, Point{mxx, mxy - x}, -1);

  // DOWN-LEFT
  ponerCuadrado(Point{mnx, mny + x}, Point{mnx + x, mny}, 1);
  if (solve(x, cnt + 1)) return true;
  ponerCuadrado(Point{mnx, mny + x}, Point{mnx + x, mny}, -1);

  // DOWN-RIGHT
  ponerCuadrado(Point{mxx - x, mny + x}, Point{mxx, mny}, 1);
  if (solve(x, cnt + 1)) return true;
  ponerCuadrado(Point{mxx - x, mny + x}, Point{mxx, mny}, -1);

  return false;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n;
  pts.resize(n);
  ll r = 0;
  FOR(i, 0, n) {
    cin >> pts[i].x >> pts[i].y;
    r = max(r, pts[i].x);
    r = max(r, pts[i].y);
  }

  auto check = [&](ll x) -> bool {
    vis.assign(n, 0);
    return solve(x, 0);
  };

  ll l = 0;

  while (r > l) {
    ll mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  cout << l << ENDL;

  return 0;
}