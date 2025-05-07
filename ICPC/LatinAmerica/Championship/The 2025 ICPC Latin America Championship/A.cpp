#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, char>>> g(n);
  vector<vector<vector<int>>> ag(n, vector<vector<int>>(26));
  FOR(i, 0, m) {
    int u, v;
    char c;
    cin >> u >> v >> c;
    u--, v--;
    g[u].push_back({v, c});
    ag[v][c - 'a'].push_back(u);
  }
  auto getID = [&](int u, int v) -> int { return u * n + v; };
  queue<pair<int, int>> q;
  vector<int> vis(n * n + 5);
  FOR(i, 0, n) {
    q.push({i, i});
    vis[getID(i, i)] = 1;
  }

  while (SZ(q)) {
    auto [u, v] = q.front();
    q.pop();

    if (u == v) {
      for (auto [next, c] : g[u]) {
        if (vis[getID(u, next)]) continue;
        vis[getID(u, next)] = 1;
        q.push({u, next});
      }
    }

    for (auto [next, cnext] : g[v]) {
      for (auto back : ag[u][cnext - 'a']) {
        if (vis[getID(back, next)]) continue;
        vis[getID(back, next)] = 1;
        q.push({back, next});
      }
    }
  }
  int ans = 0;
  FOR(i, 0, n) FOR(j, 0, n) ans += vis[getID(i, j)];

  cout << ans - n << '\n';

  return 0;
}