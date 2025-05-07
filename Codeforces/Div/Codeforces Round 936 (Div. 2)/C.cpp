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

vector<vi> g;
int cnt = 0;

int dfs(int u, int p, int x) {
  int sz = 1;
  for (auto v : g[u]) {
    if (v == p) continue;
    sz += dfs(v, u, x);
  }
  if (sz >= x) {
    cnt++;
    return 0;
  }
  return sz;
}

void solve() {
  int n, k;
  cin >> n >> k;
  g.assign(n, vi());
  FOR(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  auto can = [&](int x) -> bool {
    cnt = 0;
    dfs(0, -1, x);
    return (cnt >= k + 1);
  };

  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (can(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}