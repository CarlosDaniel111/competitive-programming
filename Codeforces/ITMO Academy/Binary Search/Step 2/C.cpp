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

ll n, x, y;

bool can(ll time) {
  ll m1 = time / x;
  ll m2 = time / y;
  return m1 + m2 >= n - 1;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n >> x >> y;

  ll l = 0, r = 1e9;
  while (l < r) {
    ll mid = (l + r) / 2;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  cout << r + min(x, y) << ENDL;

  return 0;
}