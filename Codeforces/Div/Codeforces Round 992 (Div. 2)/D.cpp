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

vi prime;

void solve() {
  int n;
  cin >> n;
  vector<vi> g(n);
  FOR(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  vi ans(n, 0);
  int curr = 1;
  auto dfs = [&](auto self, int u, int p) -> void {
    ans[u] = curr++;
    for (auto v : g[u]) {
      if (v == p) continue;
      while (prime[curr - ans[u]]) curr++;
      self(self, v, u);
    }
  };
  dfs(dfs, 0, -1);
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int mx = 4e5 + 5;
  prime.assign(mx + 5, 1);
  prime[0] = prime[1] = 0;
  for (int i = 2; i * i <= mx; i++)
    if (prime[i])
      for (int j = i * i; j <= mx; j += i) prime[j] = 0;

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}