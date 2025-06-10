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

vi ans;
void solve() {
  ll n;
  cin >> n;
  cout << ans[n - 1] << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ans.pb(1);
  ans.pb(2);
  ll curr = 3;
  ll aum = 2;
  FOR(i, 0, 251) {
    ans.pb(curr);
    curr += aum;
    ans.pb(curr);
    curr += aum;
    aum++;
  }

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}