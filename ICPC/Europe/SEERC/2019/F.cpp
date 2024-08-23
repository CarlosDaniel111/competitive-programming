#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<vi> g(n);
  FOR(i, 1, n) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  vi dp(n, 0);
  auto dfs = [&](auto self, int u, int p) -> void {
    for (auto v : g[u]) {
      if (v == p) continue;
      self(self, v, u);
      dp[u] += dp[v];
    }
    if (dp[u] == 0)
      dp[u] = 1;
    else
      dp[u]--;
  };
  dfs(dfs, 0, -1);
  if (dp[0] == 0)
    cout << "Bob" << ENDL;
  else
    cout << "Alice" << ENDL;

  return 0;
}