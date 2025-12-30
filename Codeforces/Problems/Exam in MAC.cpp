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
  ll n, c;
  cin >> n >> c;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  ll ans = (c + 1) * (c + 2) / 2;
  ll even = 0, odd = 0;
  FOR(i, 0, n) {
    // x + y = a[i]
    ans -= a[i] / 2 + 1;
    // x - y = a[i];
    ans -= c - a[i] + 1;
    if (a[i] & 1) {
      odd++;
      ans += odd;
    } else {
      even++;
      ans += even;
    }
  }
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}