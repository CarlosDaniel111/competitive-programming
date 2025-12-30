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

const ll LG = 20, INF = 1e15, MOD = 998244353;

ll be(ll a, ll b, ll m = MOD) {
  ll res = 1;
  a %= m;
  while (b) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, m;
  cin >> n >> m;
  vector<vi> g(n), g2(n);
  FOR(i, 0, m) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g2[v].pb(u);
  }
  vector<vi> dist;
  auto bfs = [&](ll t) -> void {
    dist[0][t] = 0;
    queue<pi> q;
    q.push({0, t});
    while (SZ(q)) {
      auto [u, currT] = q.front();
      q.pop();
      vi &gn = (currT - t) % 2 == 0 ? g[u] : g2[u];
      vi &gr = (currT - t) % 2 != 0 ? g[u] : g2[u];

      for (auto v : gn) {
        if (dist[u][currT] + 1 < dist[v][currT]) {
          dist[v][currT] = dist[u][currT] + 1;
          q.push({v, currT});
        }
      }
      if (currT) {
        for (auto v : gr) {
          if (dist[u][currT] + 1 < dist[v][currT - 1]) {
            dist[v][currT - 1] = dist[u][currT] + 1;
            q.push({v, currT - 1});
          }
        }
      }
    }
  };

  ll ans = INF;
  FOR(i, 0, LG) {
    if (1ll << i > ans) break;
    dist.assign(n, vi(LG, INF));
    bfs(i);
    ans = min(ans, dist[n - 1][0] + (1ll << i) - 1);
  }
  if (ans < INF) {
    cout << ans << ENDL;
    return 0;
  }

  vector<vector<tuple<ll, ll, ll>>> g3(n * 2);
  FOR(u, 0, n) {
    g3[u].pb({u + n, 1, 0});
    g3[u + n].pb({u, 1, 0});
    for (auto v : g[u]) {
      g3[u].pb({v, 0, 1});
      g3[v + n].pb({u + n, 0, 1});
    }
  }

  vector<pi> d(2 * n, {INF, INF});
  priority_queue<tuple<ll, ll, ll>> pq;
  pq.push({0, 0, 0});
  d[0] = {0, 0};
  while (SZ(pq)) {
    auto [a, b, u] = pq.top();
    pq.pop();
    for (auto [v, va, vb] : g3[u]) {
      if (d[v] > make_pair(d[u].first + va, d[u].second + vb)) {
        d[v] = {d[u].first + va, d[u].second + vb};
        pq.push({-d[v].first, -d[v].second, v});
      }
    }
  }
  if (d[n - 1] < d[2 * n - 1]) {
    ans = be(2, d[n - 1].first) - 1 + d[n - 1].second % MOD;
  } else {
    ans = be(2, d[2 * n - 1].first) - 1 + d[2 * n - 1].second % MOD;
  }
  cout << ans << ENDL;

  return 0;
}