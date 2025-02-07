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
  ll n, m, q;
  cin >> n >> m >> q;
  vector<pi> seg;
  seg.pb({1, -q});
  seg.pb({m, m});
  seg.pb({n + q + 1, n});
  while (q--) {
    ll x;
    cin >> x;
    bool dentro = false;
    for (auto &[l, r] : seg) {
      if (x < l)
        l = max(1ll, l - 1);
      else if (x > r)
        r = min(n, r + 1);
      else {
        dentro = true;
        if (l == r) l = n + q, r = -q;
      }
    }

    if (dentro) {
      seg[0] = {1ll, max(seg[0].second, 1ll)};
      seg[2] = {min(seg[2].first, n), n};
    }

    ll ans = 0;
    ll L = 0, R = -1;
    for (auto [l, r] : seg) {
      if (l > r) continue;
      if (l > R) {
        ans += max(0ll, R - L + 1);
        L = l, R = r;
      }
      R = max(R, r);
    }
    ans += max(0ll, R - L + 1);
    cout << ans << " ";
  }
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}