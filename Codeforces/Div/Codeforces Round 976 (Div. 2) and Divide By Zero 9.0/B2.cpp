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

vi aux;

bool isCuadrado(ll x) {
  ll aux = sqrt(x);
  return aux * aux == x;
}

int cuadrado(ll x) {
  ll l = 1, r = 2e9;
  while (l < r) {
    ll mid = (l + r + 1) / 2;
    if (mid * mid > x)
      r = mid - 1;
    else
      l = mid;
  }
  return l;
}

void solve() {
  ll k;
  cin >> k;
  ll l = 1, r = 3e18;
  while (l < r) {
    ll mid = (l + r + 1) / 2;
    if (mid - cuadrado(mid) > k)
      r = mid - 1;
    else
      l = mid;
  }
  if (isCuadrado(l)) l--;
  cout << l << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}