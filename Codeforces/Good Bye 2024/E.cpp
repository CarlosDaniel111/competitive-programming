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
  vector<vi> g(n);
  FOR(i, 1, n) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  vi hoja(n, 0), win(n, 0);
  FOR(i, 0, n) {
    if (SZ(g[i]) == 1) {
      hoja[i] = 1, win[i] = 1;
      for (auto v : g[i]) win[v] = 1;
    }
  }
  ll cntH = 0, cntW = 0;
  FOR(i, 0, n) {
    cntH += hoja[i];
    cntW += win[i];
  }
  ll ans = cntH * (n - cntH);
  FOR(i, 0, n) {
    if (!hoja[i] && win[i]) {
      ll cnt = 0;
      for (auto v : g[i]) cnt += (!hoja[v]);
      ans += (cnt - 1) * (n - cntW);
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