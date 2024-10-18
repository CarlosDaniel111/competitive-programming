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
  vi a(n);
  ll sum = 0;
  FOR(i, 0, n) {
    cin >> a[i];
    sum += a[i];
  }

  if (n <= 2) {
    cout << -1 << ENDL;
    return;
  }

  auto can = [&](ll x) -> bool {
    double avg = (1.0 * sum + x) / ((1.0 * n) * 2);
    ll cnt = 0;
    FOR(i, 0, n) {
      if (avg > (1.0 * a[i])) cnt++;
    }
    return (cnt * 2 > n);
  };
  ll l = 0, r = 1e15;
  while (l < r) {
    ll m = (l + r) / 2;
    if (can(m))
      r = m;
    else
      l = m + 1;
  }
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