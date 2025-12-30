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
  vector<pi> edges(m);
  FOR(i, 0, m) {
    cin >> edges[i].first >> edges[i].second;
    edges[i].first--, edges[i].second--;
  }
  vi vis;
  auto ciclo = [&](auto dfs, int u, vector<vi> &g) -> bool {
    vis[u] = 1;
    bool ciclo = 0;
    for (auto v : g[u]) {
      if (vis[v] == 1) return true;
      if (vis[v] == 0 && dfs(dfs, v, g)) return true;
    }
    vis[u] = 2;
    return false;
  };

  auto can = [&](int x) -> bool {
    vector<vi> g(n);
    vis.assign(n, 0);
    FOR(i, 0, x) { g[edges[i].first].pb(edges[i].second); }
    bool ans = 0;
    FOR(i, 0, n) {
      if (!vis[i] && ciclo(ciclo, i, g)) return true;
    }
    return false;
  };

  if (!can(m)) {
    cout << -1 << ENDL;
    return 0;
  }

  int l = 1, r = m;
  while (l < r) {
    int mid = (l + r) / 2;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << ENDL;

  return 0;
}