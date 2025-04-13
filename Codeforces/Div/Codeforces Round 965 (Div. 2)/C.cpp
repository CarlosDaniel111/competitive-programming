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
  ll n, k;
  cin >> n >> k;
  vector<pi> a(n);
  FOR(i, 0, n) cin >> a[i].first;
  FOR(i, 0, n) cin >> a[i].second;

  sort(ALL(a));
  ll opc1 = 0;
  ROF(i, n, 0) {
    if (a[i].second) {
      ll md;
      if (i < n / 2)
        md = a[n / 2].first;
      else
        md = a[(n - 2) / 2].first;
      opc1 = a[i].first + k + md;
      break;
    }
  }

  auto can = [&](ll med) -> bool {
    ll cnt = 0;
    vi men;
    ROF(i, n - 1, 0) {
      if (a[i].first >= med)
        cnt++;
      else if (a[i].second)
        men.pb(med - a[i].first);
    }

    ll curr = k;
    for (auto x : men) {
      if (curr >= x) curr -= x, cnt++;
    }
    return (cnt >= (n + 1) / 2);
  };

  ll l = 0, r = 2e9;
  while (l < r) {
    ll mid = (l + r + 1) / 2;
    if (can(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << max(opc1, a[n - 1].first + l) << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}