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
  ll n, x, y;
  cin >> n >> x >> y;
  vi a(n);
  ll sum = 0;
  FOR(i, 0, n) {
    cin >> a[i];
    sum += a[i];
  }
  a.pb(1e12);
  sort(ALL(a));
  ll ans = 0;
  FOR(i, 0, n) {
    ll l = i + 1, r = n;
    while (l < r) {
      ll mid = (l + r) / 2;
      if (sum - (a[i] + a[mid]) < x) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    ll mxj = r;
    l = i + 1, r = n + 1;
    while (l < r) {
      ll mid = (l + r) / 2;
      if (sum - (a[i] + a[mid]) <= y) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    // 31
    ll mnj = l;
    ans += mxj - mnj;
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