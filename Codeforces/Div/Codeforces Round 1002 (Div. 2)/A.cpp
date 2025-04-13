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
  set<ll> a, b;
  FOR(i, 0, n) {
    ll x;
    cin >> x;
    a.insert(x);
  }
  FOR(i, 0, n) {
    ll x;
    cin >> x;
    b.insert(x);
  }

  if (SZ(a) > 1 && SZ(b) > 1) {
    cout << "YES" << ENDL;
    return;
  }
  if (SZ(a) >= 3 or SZ(b) >= 3) {
    cout << "YES" << ENDL;
    return;
  }
  cout << "NO" << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}