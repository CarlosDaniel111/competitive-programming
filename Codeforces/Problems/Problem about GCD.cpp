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
  ll l, r, G;
  cin >> l >> r >> G;
  ll L = (l + G - 1) / G, R = r / G;
  FOR(i, 0, R - L + 1) {
    FOR(j, 0, i + 1) {
      if (gcd(L + j, R - i + j) == 1) {
        cout << G * (j + L) << " " << G * (R - i + j) << ENDL;
        return;
      }
    }
  }
  cout << "-1 -1" << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}