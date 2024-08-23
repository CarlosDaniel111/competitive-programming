#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

vector<vi> korasaju(vector<vi> &g, vector<vi> &gT) {
  int n = SZ(g), pass = 1;
  vector<vi> scc;
  vi last_vis(n, 0), S;
  auto dfs = [&](auto self, int u) -> void {
    if (pass == 2) scc.back().pb(u);
    last_vis[u] = pass;
    for (auto v : pass == 1 ? g[u] : gT[u])
      if (last_vis[v] != pass) self(self, v);
    if (pass == 1) S.pb(u);
  };
  FOR(u, 0, n)
  if (last_vis[u] != pass) dfs(dfs, u);
  pass = 2;
  reverse(ALL(S));
  for (auto &u : S)
    if (last_vis[u] != pass) {
      scc.pb({});
      dfs(dfs, u);
    }
  return scc;
}

vi comp;
vector<vi> dp;
vector<vi> g, gt;

void dfs(int u, int d, vector<pi> &to, set<int> vis) {
  vis.insert(u);
  to.pb({u, d});
  for (int v : g[u]) {
    if (comp[u] == comp[v] && !vis.count(v)) {
      dfs(v, d + 1, to, vis);
    }
  }
}

int solve(int u, int opc) {
  int &ans = dp[u][opc];
  if (ans != -1) return ans;
  ans = 0;
  if (opc == 1) {
    set<int> vis;
    vector<pi> to;
    dfs(u, 1, to, vis);
    for (auto &[v, d] : to) {
      ans = max(ans, solve(v, 0) + d);
    }
  } else {
    for (auto v : g[u]) {
      if (comp[u] != comp[v]) {
        ans = max(ans, solve(v, 1));
      }
    }
  }
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  g.assign(n + 5, vi());
  gt.assign(n + 5, vi());
  comp.assign(n + 5, 0);
  dp.assign(n + 5, vi(5, -1));

  FOR(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    gt[v].pb(u);
  }
  vector<vi> scc = korasaju(g, gt);

  FOR(i, 0, SZ(scc)) {
    for (auto x : scc[i]) {
      comp[x] = i;
    }
  }
  int ans = 0;
  FOR(i, 0, n) {
    ans = max(ans, solve(i, 1));
  }
  cout << ans << ENDL;

  return 0;
}