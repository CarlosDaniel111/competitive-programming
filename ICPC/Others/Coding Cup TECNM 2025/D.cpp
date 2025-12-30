#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using ld = long double;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

const ld EPS = 1e-9;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int m;
  cin >> m;
  unordered_map<ll, vector<ll>> g;
  ll target = 1;
  set<ll> nodes;
  FOR(i, 0, m) {
    ll u, v;
    cin >> u >> v;
    nodes.insert(u);
    nodes.insert(v);
    g[u].pb(v);
    target = max(target, max(u, v));
  }

  unordered_map<ll, ld> dist;
  unordered_map<ll, ll> parent;
  for (ll node : nodes) dist[node] = 1e300L;
  dist[1] = 0.0;
  priority_queue<pair<ld, ll>> pq;
  pq.push({0.0, 1});

  while (SZ(pq)) {
    auto [d, u] = pq.top();
    pq.pop();
    d = -d;
    auto it = g.find(u);
    if (it == g.end()) continue;
    for (ll v : it->second) {
      ld w = log(ld(v));
      ld nextD = d + w;
      if (nextD + EPS < dist[v]) {
        dist[v] = nextD;
        parent[v] = u;
        pq.push({-nextD, v});
      }
    }
  }

  vector<ll> path;
  while (target != 1) {
    path.pb(target);
    target = parent[target];
  }
  path.pb(1);
  reverse(ALL(path));
  for (auto u : path) cout << u << " ";

  return 0;
}