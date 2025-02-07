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
  ll n, a, b, c;
  cin >> n >> a >> b >> c;
  ll ans = (n / (a + b + c)) * 3;
  n = n % (a + b + c);
  if (n == 0) {
    cout << ans << ENDL;
    return;
  }
  if (a >= n) {
    cout << ans + 1 << ENDL;
    return;
  }
  if (a + b >= n) {
    cout << ans + 2 << ENDL;
    return;
  }
  if (a + b + c >= n) {
    cout << ans + 3 << ENDL;
    return;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}