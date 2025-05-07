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
  vector<ll> a(n);
  FOR(i, 0, n) cin >> a[i];
  auto can = [&](ll x) -> bool {
    ll falta = 0;
    ROF(i, n, 0) {
      if (a[i] < x)
        falta += x - a[i];
      else
        falta = max(0ll, falta - (a[i] - x));
    }
    return falta == 0;
  };
  ll l = 0, r = 1e12;
  while (l < r) {
    ll m = (l + r + 1) / 2;
    if (can(m))
      l = m;
    else
      r = m - 1;
  }
  ll mn = l;

  auto can2 = [&](ll x) -> bool {
    ll sobra = 0;
    ROF(i, n, 0) {
      if (a[i] <= x)
        sobra += x - a[i];
      else {
        if (sobra < a[i] - x) return false;
        sobra -= a[i] - x;
      }
    }
    return true;
  };

  l = 0, r = 1e12;
  while (l < r) {
    ll m = (l + r) / 2;
    if (can2(m))
      r = m;
    else
      l = m + 1;
  }

  cout << l - mn << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}