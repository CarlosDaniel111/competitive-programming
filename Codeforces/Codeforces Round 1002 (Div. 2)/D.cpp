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

void solve() {
  ll n;
  ll s1, s2;
  cin >> n >> s1 >> s2;
  s1--, s2--;
  vector<vi> g1(n), g2(n);
  set<pi> edges1, edges2;
  ll m1, m2;
  cin >> m1;
  FOR(i, 0, m1) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g1[u].pb(v);
    g1[v].pb(u);
    edges1.insert({min(u, v), max(u, v)});
  }
  cin >> m2;
  FOR(i, 0, m2) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g2[u].pb(v);
    g2[v].pb(u);
    edges2.insert({min(u, v), max(u, v)});
  }

  priority_queue<tuple<int, int, int>> pq;
  pq.push({0, s1, s2});
  vector<vi> dist(n, vi(n, INF));
  dist[s1][s2] = 0;
  while (SZ(pq)) {
    auto [d, u1, u2] = pq.top();
    pq.pop();
    d *= -1;

    if (d > dist[u1][u2]) continue;

    for (auto v1 : g1[u1]) {
      for (auto v2 : g2[u2]) {
        if (d + abs(v1 - v2) < dist[v1][v2]) {
          dist[v1][v2] = d + abs(v1 - v2);
          pq.emplace(-dist[v1][v2], v1, v2);
        }
      }
    }
  }

  ll ans = INF;
  FOR(i, 0, n) {
    FOR(j, 0, n) {
      if (edges1.count({min(i, j), max(i, j)}) &&
          edges2.count({min(i, j), max(i, j)})) {
        ans = min(ans, dist[i][i]);
        ans = min(ans, dist[j][j]);
      }
    }
  }
  if (ans == INF) ans = -1;
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}