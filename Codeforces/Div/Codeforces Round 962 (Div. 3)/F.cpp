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
  vi a(n), b(n);
  FOR(i, 0, n) { cin >> a[i]; }
  FOR(i, 0, n) { cin >> b[i]; }

  auto can = [&](ll x) -> bool {
    ll cnt = 0;
    FOR(i, 0, n) {
      if (a[i] >= x) {
        cnt += (a[i] - x) / b[i] + 1;
      }
    }
    return cnt >= k;
  };

  ll l = 0, r = 1e9 + 5;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    if (can(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }

  ll ans = 0;
  ll cnt = 0;
  FOR(i, 0, n) {
    if (a[i] >= l) {
      ll curr = (a[i] - l) / b[i] + 1;

      ans += curr * a[i] - curr * (curr - 1) / 2 * b[i];
      cnt += curr;
    }
  }
  ans -= l * (cnt - k);
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}