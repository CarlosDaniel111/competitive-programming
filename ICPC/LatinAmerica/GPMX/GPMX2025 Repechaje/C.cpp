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

  int n;
  cin >> n;
  ll x = 0;
  FOR(i, 0, n + 1) {
    int y;
    cin >> y;
    if (y) x += (1ll << (n - i));
  }
  int ans = 0;
  while (x != 1) {
    ans++;
    if (!(x & 1)) {
      x = x >> 1ll;
      continue;
    }
    ll nextX = (x << 1ll);
    FOR(k, 0, 60) {
      if ((x >> k) & 1) {
        if ((nextX >> k) & 1)
          nextX -= (1 << k);
        else
          nextX += (1 << k);
      }
    }
    if (nextX & 1) {
      nextX--;
    } else {
      nextX++;
    }
    x = nextX;
  }
  cout << ans << ENDL;

  return 0;
}