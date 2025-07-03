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
  ll n, s, x;
  cin >> n >> s >> x;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  ll ans = 0;
  ll l = 0;
  while (l < n) {
    while (l < n && a[l] > x) l++;
    ll r = l;
    while (r < n && a[r] <= x) r++;
    ll fi = -1, last = -1;
    FOR(i, l, r) {
      if (a[i] == x) {
        if (fi == -1) fi = i;
        last = i;
      }
    }
    if (fi == -1) {
      l = r;
      continue;
    }
    map<ll, ll> mp;
    ll sum = 0;
    vi llevo = {0};
    FOR(i, l, r) {
      sum += a[i];
      ll need = sum - s;
      if (a[i] == x) {
        for (auto x : llevo) mp[x]++;
        llevo.clear();
      }
      llevo.pb(sum);
      ans += mp[need];
    }

    l = r;
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