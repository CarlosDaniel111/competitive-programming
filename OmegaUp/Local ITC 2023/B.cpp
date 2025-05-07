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

vector<vi> comp;
vi scc(vector<vi>& g) {
  int n = SZ(g), t = 0, ncomps = 0;
  vi tin(n), scc(n, -1), z;
  auto dfs = [&](auto&& self, int u) -> int {
    int low = tin[u] = ++t, x;
    z.push_back(u);
    for (auto v : g[u])
      if (scc[v] < 0) low = min(low, tin[v] ?: self(self, v));
    if (low == tin[u]) {
      comp.pb(vi());
      do {
        x = z.back();
        z.pop_back();
        comp[ncomps].pb(x);
        scc[x] = ncomps;
      } while (x != u);
      ncomps++;
    }
    return tin[u] = low;
  };
  FOR(i, 0, n) if (scc[i] == -1) dfs(dfs, i);
  return scc;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<vi> g(n);
  FOR(i, 0, m) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
  }
  scc(g);
  int mx = 0;
  for (auto x : comp) {
    mx = max(mx, SZ(x));
  }
  set<int> ans;
  for (auto x : comp) {
    if (SZ(x) == mx) {
      for (auto y : x) {
        ans.insert(y);
      }
    }
  }
  for (auto x : ans) {
    cout << x << " ";
  }

  return 0;
}