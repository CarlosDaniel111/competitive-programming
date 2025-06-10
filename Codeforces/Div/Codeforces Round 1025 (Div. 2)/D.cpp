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
  ll n, m, l;
  cin >> n >> m >> l;
  vi a(l);
  ll sum = 0, mn = 1e15;
  FOR(i, 0, l) {
    cin >> a[i];
    sum += a[i];
    if (a[i] & 1) mn = min(mn, a[i]);
  }
  vector<vi> g(n);
  FOR(i, 0, m) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  vector<vi> dist(n, vi(2, 1e15));
  dist[0][0] = 0;
  queue<pi> q;
  q.push({0, 0});
  while (SZ(q)) {
    auto [u, p] = q.front();
    q.pop();
    for (auto v : g[u]) {
      if (dist[v][!p] > dist[u][p] + 1) {
        dist[v][!p] = dist[u][p] + 1;
        q.push({v, !p});
      }
    }
  }
  FOR(i, 0, n) {
    if (sum % 2 == 0) {
      if (sum - mn >= dist[i][1] or sum >= dist[i][0]) {
        cout << 1;
        continue;
      }
    } else {
      if (sum >= dist[i][1] or sum - mn >= dist[i][0]) {
        cout << 1;
        continue;
      }
    }
    cout << 0;
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