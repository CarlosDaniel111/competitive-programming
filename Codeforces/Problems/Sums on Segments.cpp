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
  vi a(n);
  ll mxi = -1;
  FOR(i, 0, n) {
    cin >> a[i];
    if (a[i] != -1 && a[i] != 1) mxi = i;
  }
  auto kadane = [a](ll l, ll r) -> pi {
    ll currmn = 0, currmx = 0;
    ll mx = 0, mn = 0;
    FOR(i, l, r) {
      currmx = max(0ll, currmx + a[i]);
      currmn = min(0ll, currmn + a[i]);
      mn = min(mn, currmn);
      mx = max(mx, currmx);
    }
    return {mn, mx};
  };

  if (mxi == -1) {
    auto [l, r] = kadane(0, n);
    cout << r - l + 1 << ENDL;
    FOR(i, l, r + 1) { cout << i << " "; }
    cout << ENDL;
    return;
  }
  auto [mn1, mx1] = kadane(0, mxi);
  auto [mn2, mx2] = kadane(mxi + 1, n);
  set<ll> ans;
  FOR(i, min(mn1, mn2), max(mx1, mx2) + 1) { ans.insert(i); }
  ll mnl, mxl, mnr, mxr;
  mnl = mxl = mnr = mxr = 0;
  ll sum = 0;
  ROF(i, mxi, 0) {
    sum += a[i];
    mnl = min(mnl, sum);
    mxl = max(mxl, sum);
  }
  sum = 0;
  FOR(i, mxi + 1, n) {
    sum += a[i];
    mnr = min(mnr, sum);
    mxr = max(mxr, sum);
  }
  FOR(i, mnl + mnr, mxl + mxr + 1) { ans.insert(i + a[mxi]); }
  cout << SZ(ans) << ENDL;
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}