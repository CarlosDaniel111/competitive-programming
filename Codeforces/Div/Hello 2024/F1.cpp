#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
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
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  set<pi> dioquis;
  set<pi> sobrante;

  ll n, q;
  cin >> n >> q;
  vi a(n), b(n);
  ll ans = 0;
  FOR(i, 0, n) {
    cin >> a[i];
  }

  FOR(i, 0, n) {
    cin >> b[i];
  }

  FOR(i, 0, n - 1) {
    ll x;
    cin >> x;
  }

  ll pen = 0;
  FOR(i, 0, n) {
    if (a[i] == b[i]) {
      ans += a[i];
      continue;
    }
    if (a[i] > b[i]) {
      ans += b[i];
      pen = a[i] - b[i];
    } else {
      ans += a[i];
      ll poder = b[i] - a[i];
      if (pen) {
        if (pen == poder) {
          sobrante.insert({i, pen});
          pen = 0;
        } else if (pen > poder) {
          sobrante.insert({i, poder});
          pen -= poder;
        } else {
          sobrante.insert({i, pen});
          pen = 0;
          dioquis.insert({i, poder - pen});
        }
      } else {
        dioquis.insert({i, poder});
      }
    }
  }

  while (q--) {
    ll p, x, y, z;
    cin >> p >> x >> y >> z;
    p--;
    if (a[p] <= b[p]) {
      ans -= a[p];
    }
    ll c = x - y;
  }

  return 0;
}