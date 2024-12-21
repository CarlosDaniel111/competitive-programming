#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
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
  cin.tie(0)->sync_with_stdio(0);
  ll n, m;
  cin >> n >> m;
  vi a(n), b(n);
  FOR(i, 0, n) { cin >> a[i] >> b[i]; }
  vector<vi> g(n);
  vector<pi> edges(m);
  FOR(i, 0, m) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
    edges[i] = {u, v};
  }
  queue<ll> q;
  vi d(n, -1);
  q.push(0);
  d[0] = 0;
  while (SZ(q)) {
    ll u = q.front();
    q.pop();
    for (auto v : g[u]) {
      if (d[v] == -1) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }

  vector<vi> g2(n * 2);
  for (auto [u, v] : edges) {
    if (d[u] > d[v]) swap(u, v);
    if (d[u] + 1 == d[v]) {
      g2[u].pb(v);
      g2[u + n].pb(v + n);
    } else if (d[u] == d[v]) {
      g2[u].pb(v + n);
      g2[v].pb(u + n);
    }
  }

  vi vis(n * 2, 0);
  vi topo;
  auto dfs = [&](auto self, ll u) -> void {
    vis[u] = true;
    for (auto v : g2[u]) {
      if (!vis[v]) self(self, v);
    }
    topo.pb(u);
  };

  FOR(i, 0, 2 * n) {
    if (!vis[i]) dfs(dfs, i);
  }

  vi dp(n * 2, -1e16);
  for (auto u : topo) {
    for (auto v : g2[u]) {
      dp[u] = max(dp[u], dp[v]);
      if (v < n)
        dp[u] = max(dp[u], a[v] - b[v] * (d[v] - 1));
      else
        dp[u] = max(dp[u], a[v - n] - b[v - n] * d[v - n]);
    }
  }

  vector<pi> c(n);
  FOR(i, 0, n) { c[i] = {a[i] - b[i] * (d[i] + 1), i}; }
  sort(c.rbegin(), c.rend());

  FOR(i, 0, n) {
    if (d[i] == 1) {
      ll ans = dp[i];
      if (c[0].second == i)
        ans = max(ans, c[1].first);
      else
        ans = max(ans, c[0].first);
      cout << ans << ENDL;
    }
  }

  return 0;
}