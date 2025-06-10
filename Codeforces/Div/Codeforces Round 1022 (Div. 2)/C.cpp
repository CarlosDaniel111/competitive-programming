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
  vi aa(n);
  FOR(i, 0, n) cin >> aa[i];
  vi a;
  ll ant = aa[0];
  FOR(i, 1, n) {
    if (aa[i] == ant) {
      continue;
    }
    a.pb(ant);
    ant = aa[i];
  }
  a.pb(ant);
  n = SZ(a);
  set<pi> pos;
  vi clone(n, 0);
  ll ans = 0;
  FOR(i, 0, n) { pos.insert({-a[i], i}); }
  for (auto &[num, idx] : pos) {
    clone[idx] = 1;
    if (idx > 0 && clone[idx - 1]) {
      continue;
    }
    if (idx < n - 1 && clone[idx + 1]) {
      continue;
    }
    ans++;
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