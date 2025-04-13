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
  cin >> m >> n;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  sort(ALL(a));
  ll ans = 0;
  FOR(i, 1, m) {
    ll cnt1 = lower_bound(ALL(a), i) - a.begin();
    cnt1 = n - cnt1;
    ll cnt2 = lower_bound(ALL(a), m - i) - a.begin();
    cnt2 = n - cnt2;
    if (cnt1 > cnt2)
      cnt1--;
    else
      cnt2--;

    // cout << cnt1 << " " << cnt2 << ENDL;
    ans += cnt1 * cnt2;
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