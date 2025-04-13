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
  ll x, y, k;
  cin >> x >> y >> k;
  ll xaux = x * k, yaux = y * k;
  if (k == 1) {
    cout << x << " " << y << ENDL;
    return;
  }
  cout << 1e5 << " " << 1e5 << ENDL;

  ll sum = 1e5;
  FOR(i, 1, k - 1) {
    sum += i;
    cout << i << " " << i << ENDL;
  }
  cout << xaux - sum << " " << yaux - sum << ENDL;
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