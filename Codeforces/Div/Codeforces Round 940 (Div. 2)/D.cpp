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

#define isOn(S, j) (S & (1 << j))

void solve() {
  ll n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n)
  cin >> a[i];
  ll ans = 0;
  ROF(k, 31, 0) {
    vector<vi> pref(n, vi(2, 0));
    vector<vi> suff(n, vi(2, 0));

    bool p = isOn(a[0], k);
    pref[0][p] = 1;
    FOR(i, 1, n) {
      if (isOn(a[i], k)) {
        pref[i][1] = pref[i - 1][0] + 1;
        pref[i][0] = pref[i - 1][1];
      } else {
        pref[i][0] = pref[i - 1][0] + 1;
        pref[i][1] = pref[i - 1][1];
      }
    }

    p = isOn(a[n - 1], k);
    suff[n - 1][p] = 1;
    ROF(i, n - 1, 0) {
      if (isOn(a[i], k)) {
        suff[i][1] = suff[i + 1][0] + 1;
        suff[i][0] = suff[i + 1][1];
      } else {
        suff[i][0] = suff[i + 1][0] + 1;
        suff[i][1] = suff[i + 1][1];
      }
    }

    FOR(i, 0, n) {
      ll m = 63 - __builtin_clzll(a[i]);
      if (m == k) {
        ans += pref[i][0] * suff[i][1] + pref[i][1] * suff[i][0];
      }
    }
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