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
  vi turn(n, 0);
  vi left(n, 0);
  ll mx = 0;
  FOR(i, 0, n) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  FOR(i, 0, n) {
    ll diff = mx - a[i] + 1;
    left[i] = (diff % k);
    left[i]--;
    (left[i] += k) %= k;
    diff += k - 1;
    turn[i] = ((diff / k) % 2);
  }
  // FOR(i, 0, n) { cout << turn[i] << " "; }
  // cout << ENDL;
  // FOR(i, 0, n) { cout << left[i] << " "; }
  // cout << ENDL;

  ll ans = mx;
  FOR(_, 0, 3) {
    ll ultprox = 0;
    FOR(i, 0, n) {
      if (turn[i] == 0) {
        ultprox = max(ultprox, k - left[i]);
      }
    }
    ans += ultprox;
    FOR(i, 0, n) {
      left[i] += ultprox;
      if (left[i] >= k) {
        turn[i] = !turn[i];
        left[i] %= k;
      }
    }
  }
  FOR(i, 0, n) {
    if (turn[i] == 0) {
      cout << -1 << ENDL;
      return;
    }
  }
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