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
  int n, q;
  cin >> n >> q;
  vector<vi> g(n);
  FOR(i, 1, n) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  vi depth(n), par(n), d(n);

  auto dfs = [&](auto self, int u, int p) -> void {
    if (depth[u] == 1) d[u] = 1;
    if (depth[u] > 1) d[u] = d[par[p]] + 2 * SZ(g[p]);
    par[u] = p;
    for (auto v : g[u]) {
      if (v == p) continue;
      depth[v] = depth[u] + 1;
      self(self, v, u);
    }
  };
  dfs(dfs, 0, -1);

  while (q--) {
    int v, p;
    cin >> v >> p;
    v--;
    int ans = d[v];
    vi aux;
    while (v != 0 && par[v] != 0) {
      aux.pb(SZ(g[par[v]]));
      v = par[par[v]];
    }
    sort(aux.rbegin(), aux.rend());
    FOR(i, 0, min(p, SZ(aux))) ans -= 2 * (aux[i] - 1);
    cout << ans << ENDL;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}