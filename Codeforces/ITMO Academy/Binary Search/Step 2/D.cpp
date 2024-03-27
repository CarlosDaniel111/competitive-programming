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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n, m;
  cin >> m >> n;
  vi t(n), z(n), y(n);
  FOR(i, 0, n) {
    cin >> t[i] >> z[i] >> y[i];
  }

  auto countBallon = [&t, &z, &y](ll i, ll time) {
    auto period = t[i] * z[i] + y[i];
    return time / period * z[i] + min((time % period) / t[i], z[i]);
  };

  auto can = [m, n, &countBallon](ll time) {
    ll cnt = 0;
    FOR(i, 0, n) {
      cnt += countBallon(i, time);
      if (cnt >= m) return true;
    }
    return false;
  };

  ll l = -1, r = m * 200;
  while (l < r) {
    auto mid = l + (r - l) / 2;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << r << ENDL;

  auto remaining = m;
  for (ll i = 0; i < n; i++) {
    auto num = countBallon(i, r);
    if (num > remaining) {
      num = remaining;
    }
    remaining -= num;
    cout << num << " ";
  }
  cout << ENDL;

  return 0;
}