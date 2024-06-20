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
  ll x, y;
  cin >> x >> y;
  vi a(32, 0), b(32, 0);
  FOR(i, 0, 32) {
    if (x & (1 << i)) {
      a[i] = true;
    }
    if (y & (1 << i)) {
      b[i] = true;
    }
  }
  ll ans = 0, curr = 0;
  FOR(i, 0, 32) {
    if (a[i] == b[i]) {
      ans++;
    } else {
      break;
    }
  }

  cout << (1 << ans) << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}