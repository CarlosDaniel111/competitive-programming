#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int xv, yv, zv, x1, y1, z1;
  cin >> xv >> yv >> zv;
  cin >> x1 >> y1 >> z1;
  vi a(6);
  FOR(i, 0, 6)
  cin >> a[i];

  int ans = 0;
  if (xv > x1) {
    ans += a[5];
    if (zv > z1)
      ans += a[3];
    else if (zv < 0)
      ans += a[2];

    if (yv > y1)
      ans += a[1];
    else if (yv < 0)
      ans += a[0];
  } else if (xv < 0) {
    ans += a[4];
    if (zv > z1)
      ans += a[3];
    else if (zv < 0)
      ans += a[2];

    if (yv > y1)
      ans += a[1];
    else if (yv < 0)
      ans += a[0];
  } else {
    if (zv < 0)
      ans += a[2];
    else if (zv > z1)
      ans += a[3];

    if (yv > y1)
      ans += a[1];
    else if (yv < 0)
      ans += a[0];
  }
  cout << ans << ENDL;

  return 0;
}