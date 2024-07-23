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
  ll n, x;
  cin >> n >> x;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  set<ll> d;
  for (ll i = 1; i * i <= x; i++) {
    if (x % i != 0) continue;
    d.insert(i);
    d.insert(x / i);
  }

  set<ll> curr;
  ll ans = 1;
  curr.insert(1);
  FOR(i, 0, n) {
    if (!d.count(a[i])) continue;
    bool mal = false;
    set<ll> curr2;
    for (auto c : curr) {
      if (c * a[i] <= x && d.count(c * a[i])) {
        // cout << c << " " << a[i] << ENDL;
        curr2.insert(c * a[i]);
        if (c * a[i] == x) {
          mal = true;
        }
      }
    }
    if (mal) {
      ans++;
      curr.clear();
      curr.insert(1);
      curr.insert(a[i]);
      continue;
    }
    for (auto c : curr2) {
      // cout << c << ENDL;
      curr.insert(c);
    }
  }
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}