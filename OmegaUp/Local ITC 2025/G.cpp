#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<ll>;

#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)

signed main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;
  vi a(n * 2);
  vi x(n * 2);
  FOR(i, 0, n) {
    cin >> x[i];
    x[i + n] = x[i];
    a[i] = x[i] - k;
    a[i + n] = a[i];
  }
  vi pref(n * 2 + 1, 0);
  FOR(i, 0, 2 * n) { pref[i + 1] = pref[i] + x[i]; }

  ll l = 0, r = 0;
  ll ans = -1;
  ll curr = 0;
  while (l < n) {
    r = max(r, l);
    while (r < 2 * n) {
      curr += a[r];
      if (curr > 0) {
        ans = max(ans, pref[r] - pref[l]);
        break;
      }
      r++;
    }
    while (curr > 0) {
      curr -= a[l];
      l++;
    }
  }
  reverse(a.begin(), a.end());
  reverse(x.begin(), x.end());
  pref.assign(n * 2 + 1, 0);
  FOR(i, 0, 2 * n) { pref[i + 1] = pref[i] + x[i]; }

  l = r = 0;
  curr = 0;
  while (l < n) {
    r = max(r, l);
    while (r < 2 * n) {
      curr += a[r];
      if (curr > 0) {
        ans = max(ans, pref[r] - pref[l]);
        break;
      }
      r++;
    }
    while (curr > 0) {
      curr -= a[l];
      l++;
    }
  }
  if (ans == 0) ans = -1;

  cout << ans << '\n';
}