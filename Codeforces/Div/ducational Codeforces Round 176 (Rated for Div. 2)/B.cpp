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
  ll n, k;
  cin >> n >> k;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  if (k == 1) {
    ll pos = a[0] + a[n - 1];
    ll ans = max(a[0], a[n - 1]);
    ll mx = 0;
    FOR(i, 1, n - 1) mx = max(mx, a[i]);
    cout << max(pos, ans + mx) << ENDL;
    return;
  }
  sort(a.rbegin(), a.rend());
  ll ans = 0;
  FOR(i, 0, min(k + 1, n)) { ans += a[i]; }
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}