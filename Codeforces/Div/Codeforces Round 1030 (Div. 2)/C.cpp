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
  ll n, X;
  cin >> n >> X;
  vi a(n);
  priority_queue<pi> pq;
  FOR(i, 0, n) {
    cin >> a[i];
    FOR(k, 0, 64) {
      if (!((a[i] >> k) & 1ll)) {
        pq.push({-k, i});
      }
    }
  }
  while (SZ(pq)) {
    auto [k, idx] = pq.top();
    pq.pop();
    k = -k;
    if ((1ll << k) > X) break;
    a[idx] += (1ll << k);
    X -= (1ll << k);
  }
  // 111
  ll ans = 0;
  FOR(i, 0, n) {
    FOR(k, 0, 64) {
      if ((a[i] >> k) & 1ll) {
        ans++;
      }
    }
  }
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}