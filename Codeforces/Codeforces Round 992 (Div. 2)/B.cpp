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
  if (n == 1)
    cout << "1" << ENDL;
  else if (n == 2)
    cout << "2" << ENDL;
  else if (n == 3)
    cout << "2" << ENDL;
  else if (n == 4)
    cout << "2" << ENDL;
  else {
    ll ans = 2;
    ll curr = 4;
    while (curr < n) {
      curr++;
      curr *= 2;
      ans++;
    }
    cout << ans << ENDL;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}