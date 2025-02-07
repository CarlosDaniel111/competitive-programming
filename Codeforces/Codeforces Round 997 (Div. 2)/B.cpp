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
  int n;
  cin >> n;
  vector<vi> g(n, vi(n, 0));
  FOR(i, 0, n) {
    string s;
    cin >> s;
    FOR(j, 0, n) {
      if (s[j] == '1') g[i][j] = 1;
    }
  }
  vi ans, vis(n, 0);
  auto dfs = [&](auto self, int u) -> void {
    vis[u] = 1;
    FOR(v, u, n) {
      if (g[u][v] && !vis[v]) {
        self(self, v);
      }
    }
    ans.pb(u);
  };

  FOR(i, 0, n) {
    if (vis[i]) continue;
    dfs(dfs, i);
  }
  reverse(ALL(ans));
  for (auto x : ans) cout << x + 1 << " ";
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}