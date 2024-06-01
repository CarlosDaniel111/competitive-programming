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

ll suma(ll n) {
  return n * (n + 1) / 2;
}

void solve() {
  ll n;
  cin >> n;
  ll ans = 0;
  FOR(i, 1, n + 1) {
    FOR(j, 1, n + 1) {
      ans += max(i, j);
    }
  }

  cout << ans << " " << 2 * n << ENDL;

  ROF(i, n + 1, 1) {
    cout << "1 " << i << " ";
    FOR(j, 1, n + 1)
    cout << j << " ";
    cout << ENDL;

    cout << "2 " << i << " ";
    FOR(j, 1, n + 1)
    cout << j << " ";
    cout << ENDL;
  }
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