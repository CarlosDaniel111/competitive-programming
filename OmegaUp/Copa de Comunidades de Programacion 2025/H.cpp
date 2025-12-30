#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, q;
  cin >> n;
  vi a(n);
  FOR(i, 0, n) {
    cin >> a[i];
    a[i]--;
  }
  cin >> q;
  while (q--) {
    ll l, r;
    cin >> l >> r;
    l--, r--;
    ll ans = 0;
    map<ll, ll> mp;
    mp[0] = 1;
    ll sum = 0;
    FOR(i, l, r + 1) {
      sum += a[i];
      ans += mp[sum];
      mp[sum]++;
    }

    cout << ans << ENDL;
  }

  return 0;
}