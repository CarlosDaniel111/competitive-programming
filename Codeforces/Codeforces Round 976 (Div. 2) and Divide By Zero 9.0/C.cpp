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
// 101 - 001

// 1110
// 1010 - 0010

#define isOn(S, j) ((S >> j) & 1)

void solve() {
  ll b, c, d;
  cin >> b >> c >> d;
  ll a = 0;
  FOR(i, 0, 63) {
    if (isOn(d, i) && isOn(b, i)) continue;
    if (!isOn(d, i) && !isOn(b, i)) continue;
    if (isOn(d, i) && !isOn(b, i)) {
      if (isOn(c, i)) {
        cout << -1 << ENDL;
        return;
      }
      a |= (1ll << i);
    }
    if (!isOn(d, i) && isOn(b, i)) {
      if (!isOn(c, i)) {
        cout << -1 << ENDL;
        return;
      }
      a |= (1ll << i);
    }
  }
  cout << a << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}