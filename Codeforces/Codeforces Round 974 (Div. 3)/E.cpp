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

constexpr ll INF = 1e15;
set<ll> c;

vector<vi> dijkstra(vector<vector<pi>>& g, ll x) {
  ll n = SZ(g);
  vector<vi> d(n, vi(2, INF));
  d[x][0] = 0;
  priority_queue<tuple<ll, ll, ll>> pq;
  pq.emplace(0, x, 0);
  while (!pq.empty()) {
    auto [du, u, cab] = pq.top();
    pq.pop();
    du *= -1;
    if (c.count(u)) cab = 1;
    if (du > d[u][cab]) continue;
    for (auto [v, w] : g[u]) {
      if (cab) w /= 2;
      if (du + w < d[v][cab]) {
        d[v][cab] = du + w;
        pq.emplace(-d[v][cab], v, cab);
      }
    }
  }
  return d;
}

void solve() {
  ll n, m, h;
  cin >> n >> m >> h;
  c.clear();
  FOR(i, 0, h) {
    ll x;
    cin >> x;
    x--;
    c.insert(x);
  }
  vector<vector<pi>> g(n);
  FOR(i, 0, m) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].pb({v, w});
    g[v].pb({u, w});
  }
  vector<vi> d1 = dijkstra(g, 0);
  vector<vi> d2 = dijkstra(g, n - 1);
  ll ans = INF;
  FOR(i, 0, n) {
    ll t1 = min(d1[i][0], d1[i][1]);
    ll t2 = min(d2[i][0], d2[i][1]);
    // cout << i << " " << t1 << " " << t2 << ENDL;
    ans = min(ans, max(t1, t2));
  }
  if (ans == INF) ans = -1;
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