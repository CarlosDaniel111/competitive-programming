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

const ll INF = 1e18;

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<vector<pi>> g(n);
  FOR(i, 0, m) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].pb({v, w});
    g[v].pb({u, w});
  }
  vi s(n);
  FOR(i, 0, n) cin >> s[i];
  vector<vi> dist(n, vi(n, INF));
  priority_queue<tuple<ll, ll, ll>> pq;
  dist[0][0] = 0;
  pq.push({0, 0, 0});
  while (SZ(pq)) {
    auto [d, u, currBicycle] = pq.top();
    pq.pop();
    d *= -1;
    if (s[u] < s[currBicycle]) currBicycle = u;
    for (auto [v, w] : g[u]) {
      if (dist[v][currBicycle] > d + w * s[currBicycle]) {
        dist[v][currBicycle] = d + w * s[currBicycle];
        pq.push({-dist[v][currBicycle], v, currBicycle});
      }
    }
  }
  cout << *min_element(ALL(dist[n - 1])) << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}