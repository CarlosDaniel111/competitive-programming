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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vi c(2), a(2);
  cin >> c[0] >> a[0] >> c[1] >> a[1];
  int e, g, h;
  cin >> e >> g >> h;
  int ans = 1e9;
  int cnta = 0, cntb = 0;
  FOR(i, 0, 255) {
    FOR(j, 0, 255) {
      int cntHojas = i * a[0] + j * a[1];
      if (cntHojas < h) {
        continue;
      }
      int cost = i * c[0] + j * c[1];
      if (cost < g) cost += e;
      if (cost < ans or (cost == ans && i < cnta)) {
        ans = cost;
        cnta = i;
        cntb = j;
      }
    }
  }
  cout << ans << " " << cnta << " " << cntb << ENDL;

  return 0;
}