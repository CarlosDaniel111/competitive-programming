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
  string s;
  cin >> s;
  ll n = SZ(s);
  list<ll> ls;
  for (auto c : s) {
    ls.pb(c - '0');
  }
  string ans = "";
  FOR(i, 0, n) {
    ll j = 0;
    ll mx = 0, pos = 0;
    auto itt = ls.begin();
    for (list<ll>::iterator it = ls.begin(); it != ls.end(); it++) {
      ll x = *it;
      if (x - j > mx) {
        mx = x - j;
        pos = j;
        itt = it;
      }
      j++;
      if (j == 11) break;
    }
    ans += (mx + '0');
    ls.erase(itt);
  }
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}