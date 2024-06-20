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
  FOR(i, 0, n) { cin >> a[i]; }

  ll mx = 1e9 - (n + 5), x = 0;
  FOR(i, 0, n) { x += ((mx / a[i]) + 1); }
  if (x >= mx) {
    cout << -1 << ENDL;
  } else {
    FOR(i, 0, n) { cout << (mx / a[i] + 1) << " "; }
    cout << ENDL;
  }
}
// 11614

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}