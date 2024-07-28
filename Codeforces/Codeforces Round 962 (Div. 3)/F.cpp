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

int n;

int ternary(int k, int i) {
  if (i == n) return 0;
  int l = 0, r = k;
  while (r - l >= 2) {
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    int f1 = calc(m1, i) + ternary(k - m1, );
    double f2 = f(m2);
    if (f1 < f2)  // Maximo de f(x)
      l = m1;
    else
      r = m2;
  }
  return f(l);
}

void solve() {
  ll x, y, k;
  cin >> x >> y >> k;
  ll k2 = k;
  ll ans = 0;
  for (ll i = x; i >= 0 && k2; i -= y, k2--) {
    ans += i;
  }
  cout << ENDL;
  /*ll ans2 = 0;
  if ((x + y - 1) / y <= k) {
    ll n = (x + y - 1) / y;
    ans2 = (n / 2.0) * (x + (x - (x / y) * y));
  } else {
    ans2 = k / 2.0 * (x + (x - (k - 1) * y));
  }*/

  ll n = min(k, x / y + 1);
  ll l = x - (n - 1) * y;
  ll ans2 = n / 2.0 * (x + l);
  cout << ans << ENDL;
  cout << ans2 << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}