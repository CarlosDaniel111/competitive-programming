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

// 110
// 11

void solve() {
  ll n, x;
  cin >> n >> x;
  if (x == 0 && n == 1) {
    cout << -1 << ENDL;
    return;
  }

  if (x == 0) {
    ll ans = 0;
    if (n & 1) {
      ans += 6;
      n -= 3;
    }
    cout << ans + n << ENDL;
    return;
  }

  ll ans = 0;
  ll cnt = 0;
  ROF(i, 32, 0) {
    if ((x >> i) & 1) {
      cnt++;
      ans += (1ll << i);
      n--;
    }
  }
  if (n <= 0) {
    cout << ans << ENDL;
    return;
  }
  if (n & 1) {
    if (cnt >= 2) {
      n++;
    } else {
      FOR(i, 0, 5) {
        if (!((x >> i) & 1)) {
          ans += (1ll << i);
          ans += (1ll << i);
          n--;
          break;
        }
      }
    }
  }
  cout << ans + n << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}