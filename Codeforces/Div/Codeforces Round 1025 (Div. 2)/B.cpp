#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

ll check(ll n, ll m) {
  ll ans = 1;
  ll area = n * m;
  while (area >= 2) {
    ans++;
    area -= max(n / 2 * m, m / 2 * n);
    if (n / 2 * m > m / 2 * n) {
      n -= (n / 2);
    } else {
      m -= (m / 2);
    }
  }
  return ans;
}

void solve() {
  ll n, m, a, b;
  cin >> n >> m >> a >> b;
  // vector<pi> aa;
  // aa.pb({a - 1, 0}), aa.pb({b - 1, 1}), aa.pb({n - a, 2}), aa.pb({m - b, 3});
  cout << min({check(a, m), check(n, b), check(n - a + 1, m),
               check(n, m - b + 1)})
       << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}