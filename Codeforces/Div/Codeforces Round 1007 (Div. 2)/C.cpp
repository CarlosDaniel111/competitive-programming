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
  int n, s, e;
  cin >> n >> s >> e;
  s--, e--;
  vector<vi> g(n);
  FOR(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  vi vis(n, 0);
  queue<int> q;
  vi ans;
  q.push(e);
  while (SZ(q)) {
    int u = q.front();
    q.pop();
    ans.pb(u);
    vis[u] = 1;
    for (auto v : g[u]) {
      if (!vis[v]) q.push(v);
    }
  }
  reverse(ALL(ans));
  for (auto x : ans) {
    cout << x + 1 << " ";
  }
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}