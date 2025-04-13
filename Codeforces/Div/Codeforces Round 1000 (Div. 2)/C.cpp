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
  multiset<ll> mst;
  FOR(i, 0, n) mst.insert(SZ(g[i]));
  ll ans = 0;
  FOR(i, 0, n) {
    mst.erase(mst.find(SZ(g[i])));
    for (auto v : g[i]) mst.erase(mst.find(SZ(g[v])));

    ll sec = -1e9;
    if (SZ(mst)) sec = *(--mst.end()) - 1;
    for (auto v : g[i]) {
      sec = max(sec, SZ(g[v]) - 2 - (SZ(g[v]) == 1));
    }

    ans = max(ans, SZ(g[i]) + sec);
    mst.insert(SZ(g[i]));
    for (auto v : g[i]) mst.insert(SZ(g[v]));
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