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
  ll n, x;
  cin >> n >> x;
  vi a(n);
  FOR(i, 0, n)
  cin >> a[i];
  vi prefix(n + 1, 0);
  FOR(i, 1, n + 1) {
    prefix[i] = prefix[i - 1] + a[i - 1];
  }
  vi dp(n + 5, 0);
  ll ans = 0;
  ROF(l, n, 0) {
    ll r = upper_bound(ALL(prefix), prefix[l] + x) - prefix.begin();
    dp[l] = r - l - 1 + dp[r];
    ans += dp[l];
  }
  cout << ans << ENDL;
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