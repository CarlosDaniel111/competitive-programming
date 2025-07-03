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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

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
  vi sz(n, 0);
  auto calc_sz = [&](auto self, int u, int p) -> void {
    sz[u] = 1;
    for (auto v : g[u])
      if (v != p) {
        self(self, v, u);
        sz[u] += sz[v];
      }
  };
  auto find_centroid = [&](auto self, int u, int p) -> int {
    for (auto v : g[u])
      if (v != p && sz[v] * 2 >= n) return self(self, v, u);
    return u;
  };
  calc_sz(calc_sz, 0, -1);
  cout << find_centroid(find_centroid, 0, -1) + 1 << ENDL;

  return 0;
}