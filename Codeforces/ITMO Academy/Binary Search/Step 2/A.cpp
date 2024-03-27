#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

ll w, h, n;

bool can(ll l) {
  ll ancho = l / w;
  ll largo = l / h;
  return ancho * largo >= n;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> w >> h >> n;

  ll l = 0, r = 1;
  while (!can(r)) r *= 2;
  while (l < r) {
    ll mid = (l + r) / 2;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << r << ENDL;

  return 0;
}