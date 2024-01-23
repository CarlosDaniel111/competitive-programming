#include <bits/stdc++.h>
using namespace std;
// AC2++
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define ROF(i, a, b) for (ll i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e5 + 5;
constexpr ll INF = 1e15;
constexpr ll LLINF = 1e18;

vector<pi> graph[MAX];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n, m, p, g;
  cin >> n >> m >> p >> g;
  p--;
  g--;
  FOR(i, 0, m) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    graph[u].pb({v, w});
    graph[v].pb({u, w});
  }

  vi dist(n, INF);
  dist[p] = 0;

  priority_queue<pi> pq;
  pq.emplace(0, p);
  while (!pq.empty()) {
    auto [du, u] = pq.top();
    du *= -1;
    pq.pop();

    if (du > dist[u])
      continue;

    for (auto &[v, dv] : graph[u]) {
      if (du + dv < dist[v]) {
        dist[v] = du + dv;
        pq.emplace(-dist[v], v);
      }
    }
  }

  vi dist2(n, INF);
  dist2[p] = 0;

  pq.emplace(0, p);
  while (!pq.empty()) {
    auto [du, u] = pq.top();
    du *= -1;
    pq.pop();

    if (du > dist2[u])
      continue;

    for (auto &[v, dv] : graph[u]) {
      if (du + dv < dist2[v] && v != g) {
        dist2[v] = du + dv;
        pq.emplace(-dist2[v], v);
      }
    }
  }

  vi ans;
  FOR(i, 0, n) {
    if (i == p || i == g) continue;
    if (dist[i] % 2 == 1) continue;
    if (dist[i] == dist2[i]) continue;
    if (dist[i] / 2 == dist[g]) {
      ans.pb(i);
    }
  }
  if (SZ(ans) == 0) {
    cout << "*" << ENDL;
    return 0;
  }
  for (auto x : ans) {
    cout << x + 1 << " ";
  }

  return 0;
}