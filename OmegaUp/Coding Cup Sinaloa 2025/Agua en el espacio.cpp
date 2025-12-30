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
  vector<vi> a(n, vi(m));
  FOR(i, 0, n) FOR(j, 0, m) cin >> a[i][j];

  vector<vi> pref(n + 1, vi(m + 1, 0));
  FOR(i, 1, n + 1) {
    FOR(j, 1, m + 1) {
      pref[i][j] = a[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] -
                   pref[i - 1][j - 1];
    }
  }

  ll q;
  cin >> q;
  while (q--) {
    ll x1, y1, x2, y2;
    char c;
    cin >> x1 >> c >> y1;
    cin >> x2 >> c >> y2;
    ll mnx = min(x1, x2), mxx = max(x1, x2), mny = min(y1, y2),
       mxy = max(y1, y2);
    ll opc1 = pref[mxx][mxy] + pref[mnx - 1][mny - 1] - pref[mxx][mny - 1] -
              pref[mnx - 1][mxy];

    cin >> x1 >> c >> y1;
    cin >> x2 >> c >> y2;
    mnx = min(x1, x2), mxx = max(x1, x2), mny = min(y1, y2), mxy = max(y1, y2);
    ll opc2 = pref[mxx][mxy] + pref[mnx - 1][mny - 1] - pref[mxx][mny - 1] -
              pref[mnx - 1][mxy];

    if (opc1 == opc2) {
      cout << 0 << ENDL;
    } else if (opc1 > opc2) {
      cout << 1 << ENDL;
    } else {
      cout << 2 << ENDL;
    }
  }

  return 0;
}