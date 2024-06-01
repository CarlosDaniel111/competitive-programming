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
  vector<ll> a(n);
  FOR(i, 0, n) {
    cin >> a[i];
  }
  ll l = 0, r = n - 1;
  while (l < r && k) {
    ll mn = min(a[l], a[r]);
    if ((mn - 1) * 2 <= k) {
      a[l] -= (mn - 1);
      a[r] -= (mn - 1);
      k -= (mn - 1) * 2;
    } else {
      break;
    }
    if (k) {
      a[l]--;
      k--;
    }
    if (k) {
      a[r]--;
      k--;
    }
    if (a[l] == 0) l++;
    if (a[r] == 0) r--;
  }
  if (l == r && a[l] <= k) {
    a[l] = 0;
  }
  ll ans = 0;
  for (auto x : a) {
    if (x == 0) ans++;
  }

  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}