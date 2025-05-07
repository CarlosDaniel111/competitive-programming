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
  ll n;
  cin >> n;
  vi aa(n);
  FOR(i, 0, n) cin >> aa[i];
  ll ans = 0;
  ll l = 0;
  while (l < n && aa[l] > 0) {
    ans += aa[l];
    l++;
  }
  ll r = n - 1;
  while (r >= 0 && aa[r] < 0) {
    ans += -aa[r];
    r--;
  }
  vi a;
  FOR(i, l, r + 1) { a.pb(aa[i]); }
  n = SZ(a);
  vi pref(n + 1, 0);
  FOR(i, 0, n) {
    if (a[i] < 0)
      pref[i + 1] = pref[i];
    else
      pref[i + 1] = pref[i] + a[i];
  }
  vi suff(n + 1, 0);
  ROF(i, n, 0) {
    if (a[i] > 0)
      suff[i] = suff[i + 1];
    else
      suff[i] = suff[i + 1] + -a[i];
  }
  ll res = 0;
  FOR(i, 0, n + 1) { res = max(res, pref[i] + suff[i]); }
  cout << ans + res << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}