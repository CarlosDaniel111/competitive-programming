#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<vi> g(n);
  FOR(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  vector<double> dist(n, 1e9);
  vector<double> sum(n, 0);
  FOR(i, 0, n) sum[i] = SZ(g[i]);
  dist[n - 1] = 0;
  priority_queue<pair<double, int>> q;
  q.push({0, n - 1});
  vi vis(n, 0), cnt(n, 0);
  while (SZ(q)) {
    auto [_, u] = q.top();
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto v : g[u]) {
      if (vis[v]) continue;
      cnt[v]++;
      sum[v] += dist[u];
      dist[v] = sum[v] / cnt[v];
      q.push({-dist[v], v});
    }
  }
  cout << setprecision(9) << fixed;
  cout << dist[0] << ENDL;

  return 0;
}