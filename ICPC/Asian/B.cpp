#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, m;
  cin >> n >> m;
  vector<vi> izq(n + 1, vi(m + 1, 0)), der(n + 1, vi(m + 1, m + 1)),
      vis(n + 1, vi(m + 1, 0));
  ll ans = n * (n + 1) / 2 * m * (m + 1) / 2;
  FOR(_, 0, n * m) {
    ll x, y;
    cin >> x >> y;
    ll l = 0, r = 1e9;
    FOR(i, x, n + 1) {
      if (vis[i][y]) break;
      l = max(l, izq[i][y]), r = min(r, der[i][y]);
      ll currL = l, currR = r;
      ROF(j, x + 1, 1) {
        if (vis[j][y]) break;
        currL = max(currL, izq[j][y]), currR = min(currR, der[j][y]);
        ans -= (y - currL) * (currR - y);
      }
    }
    for (ll i = y; i <= m && !vis[x][i]; i++) izq[x][i] = y;
    for (ll i = y; i >= 1 && !vis[x][i]; i--) der[x][i] = y;

    vis[x][y] = 1;
    cout << ans << ENDL;
  }

  return 0;
}