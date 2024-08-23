#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  vector<vi> g(n, vi());
  vi c(n);
  for (auto &x : c) cin >> x;
  FOR(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  int ans = 0;
  FOR(i, 0, n) {
    vector<vi> dist(n, vi(2, INF));
    queue<pi> q;
    dist[i][0] = 0;
    q.push({i, 0});
    while (SZ(q)) {
      auto [u, op] = q.front();
      q.pop();
      for (int v : g[u]) {
        int o = op ^ (c[u] != c[v]);
        if (dist[v][o] > dist[u][op] + 1) {
          dist[v][o] = dist[u][op] + 1;
          q.push({v, o});
        }
      }
    }
    FOR(j, 0, n) {
      FOR(t, 0, k + 1) {
        ans = max(ans, min(dist[j][0] + t, dist[j][1] + (k - t)));
      }
    }
  }
  cout << ans << ENDL;

  return 0;
}