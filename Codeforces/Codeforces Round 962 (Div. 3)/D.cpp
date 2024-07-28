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
  ll n, x;
  cin >> n >> x;
  ll lim = ((n + 1) / 2 - 1);
  ll ans = 0;
  FOR(a, 1, lim + 1) {
    FOR(b, 1, lim + 1) {
      ll c = min((n - a * b) / (a + b), x - a - b);
      // cout << a << " " << b << " " << c << ENDL;
      if (c <= 0 || a + b + c > x || a * b + a * c + b * c > n) break;
      ans += c;
    }
  }
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}