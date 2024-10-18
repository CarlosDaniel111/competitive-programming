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

constexpr ll INF = 5e8;

void solve() {
  ll n, m, A, B;
  cin >> n >> m >> A >> B;
  vector<vi> g(n, vi());
  FOR(i, 0, m) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  vi a(n);
  FOR(i, 0, n) { cin >> a[i]; }
  FOR(i, 1, n) a[i] += B;

  if (A <= B) {
    priority_queue<pi> q;
    vi dist(n, INF);
    dist[0] = 0;
    q.push({0, 0});
    while (SZ(q)) {
      auto [_, u] = q.top();
      q.pop();
      for (auto v : g[u]) {
        if (a[v] + B * dist[u] < a[0] + A * dist[u] && dist[u] + 1 < dist[v]) {
          dist[v] = dist[u] + 1;
          q.push({-dist[v], v});
        }
      }
    }
    if (dist[n - 1] == INF) dist[n - 1] = -1;
    cout << dist[n - 1] << ENDL;
    return;
  }

  priority_queue<pi> q;
  vi vis(n, 0);  // 0 - no visitado, 1 - progress, 2 - alcanzable
  q.push({0, 0});
  ll currLevel = a[0];
  while (SZ(q)) {
    auto [_, u] = q.top();
    q.pop();
    if (u != 0 && a[u] >= currLevel) continue;
    if (u != 0) currLevel += A - B;
    vis[u] = 2;
    for (auto v : g[u]) {
      if (vis[v]) continue;
      q.push({-a[v], v});
      vis[v] = 1;
    }
  }
  if (vis[n - 1] != 2) {
    cout << -1 << ENDL;
    return;
  }
  q.push({0, 0});
  vi dist(n, INF);
  dist[0] = 0;
  while (SZ(q)) {
    auto [_, u] = q.top();
    q.pop();
    for (auto v : g[u]) {
      if (vis[v] != 2) continue;
      ll mnDist = (a[v] - a[0]) / (A - B) + 1;
      if (a[0] > a[v]) mnDist = 0;
      if (dist[v] > max(dist[u], mnDist) + 1) {
        dist[v] = max(dist[u], mnDist) + 1;
        q.push({-dist[v], v});
      }
    }
  }
  if (dist[n - 1] == INF) dist[n - 1] = -1;
  cout << dist[n - 1] << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}