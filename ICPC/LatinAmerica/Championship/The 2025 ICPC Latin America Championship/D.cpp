#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)

struct DSU {
  int n, cnt;
  vector<int> e, sz;
  vector<ll> val;
  DSU(int n) : n(n), cnt(0), e(2 * n, -1), sz(2 * n), val(2 * n, 0) {
    fill(sz.begin(), sz.begin() + n, 1);
  }

  void upd(int x) {
    if (e[x] < 0) {
      return;
    }
    upd(e[x]);
    if (e[e[x]] != -1) {
      val[x] += val[e[x]];
    }
  }
  int compress(int x) {
    if (e[x] < 0) {
      return x;
    }
    return e[x] = compress(e[x]);
  }
  int get(int x) {
    upd(x);
    return compress(x);
  }

  void join(int x, int y, ll d) {
    x = get(x);
    y = get(y);
    val[x] += d * sz[y];
    val[y] += d * sz[x];
    e[x] = n + cnt;
    e[y] = n + cnt;
    sz[n + cnt] = sz[x] + sz[y];
    ++cnt;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<int> d(n);
  for (int& x : d) {
    cin >> x;
  }

  vector<vector<int>> g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) -> bool { return d[i] < d[j]; });

  DSU dsu(n);
  for (int u : p) {
    for (int v : g[u]) {
      int x = dsu.get(u), y = dsu.get(v);
      if (x != y && d[v] <= d[u]) {
        dsu.join(x, y, d[u]);
      }
    }
  }
  for (int u = 0; u < n; ++u) {
    dsu.get(u);
    ll val = d[u] + dsu.val[u];
    if (dsu.e[u] != -1) {
      val += dsu.val[dsu.e[u]];
    }
    cout << val << " \n"[u == n - 1];
  }

  return 0;
}