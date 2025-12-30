#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  a--, b--;
  vector<vi> g(n);

  FOR(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  vi p(n, -1);
  int db;
  auto dfs1 = [&](auto dfs, int u, int d = 0) -> void {
    if (u == b) db = d;
    for (auto v : g[u])
      if (v != p[u]) {
        p[v] = u;
        dfs(dfs, v, d + 1);
      }
  };
  dfs1(dfs1, a);

  int u = b;
  FOR(_, 0, (db + 1) / 2) { u = p[u]; }
  int mx = 0;
  auto dfs2 = [&](auto dfs, int u, int p = -1, int d = 0) -> void {
    mx = max(mx, d);
    for (auto v : g[u])
      if (v != p) {
        dfs(dfs, v, u, d + 1);
      }
  };
  dfs2(dfs2, u);
  cout << 2 * (n - 1) - mx + ((db + 1) / 2) << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}