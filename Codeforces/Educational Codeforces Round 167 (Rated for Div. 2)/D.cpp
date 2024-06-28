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

void solve() {
  ll n, m;
  cin >> n >> m;
  vi a(n), b(n), c(m);
  FOR(i, 0, n)
  cin >> a[i];
  FOR(i, 0, n)
  cin >> b[i];
  FOR(i, 0, m)
  cin >> c[i];
  vector<pi> costo(n);
  FOR(i, 0, n)
  costo[i] = {a[i], a[i] - b[i]};
  sort(ALL(costo));
  vi dp(1000005, 0);
  ll pt = 0;
  pi mejor = {0, 1e9 + 5};
  FOR(i, 1, 1000005) {
    while (pt < n) {
      if (costo[pt].first <= i) {
        if (costo[pt].second < mejor.second) {
          mejor = costo[pt];
        }
        pt++;
      } else
        break;
    }

    if (mejor.second < 1e9 + 5) {
      dp[i] = dp[i - mejor.second] + 2;
    }
  }
  ll ans = 0;
  FOR(i, 0, m) {
    if (c[i] >= (ll)1e6 + 5) {
      ll veces = (c[i] - mejor.first + 1) / mejor.second;
      ans += (2 * veces + dp[c[i] - veces * mejor.second]);
    } else {
      ans += dp[c[i]];
    }
  }

  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;

  while (t--)
    solve();

  return 0;
}