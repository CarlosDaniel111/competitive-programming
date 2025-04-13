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

constexpr ll INF = 3e16;

void solve() {
  ll n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n)
  cin >> a[i];
  ll ans = 0;
  if (n % 2 == 1) {
    for (ll i = 1; i < n; i += 2) {
      ll mx = max(a[i - 1], a[i + 1]);
      if (a[i] <= mx) ans += mx - a[i] + 1;
    }
    cout << ans << ENDL;
    return;
  }

  auto falta = [&](ll i) -> ll {
    ll res = 0;
    ll mx = max(a[i - 1], a[i + 1]);
    if (a[i] <= mx) res += mx - a[i] + 1;
    return res;
  };

  vector<vi> dp(n + 1, vi(2, INF));
  dp[0][0] = dp[1][0] = dp[1][1] = dp[1][1] = 0;

  FOR(i, 2, n) {
    dp[i][0] = falta(i - 1) + dp[i - 2][0];
  }
  dp[2][1] = 0;
  FOR(i, 3, n) {
    dp[i][1] = min({dp[i - 2][1],
                    dp[i - 3][0]}) +
               falta(i - 1);
  }

  cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 2][0]}) << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}