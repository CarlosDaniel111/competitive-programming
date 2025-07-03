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

struct DSU {
  vector<int> e;
  vector<pi> st;
  void init(int n) { e = vi(n, -1); }
  int size(int x) { return -e[get(x)]; }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<vi> g(n);
  DSU dsu;
  dsu.init(n);
  vi e(n);
  FOR(i, 0, n) cin >> e[i];
  FOR(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  vi id(n);
  vi ans(n);
  iota(ALL(id), 0);
  sort(ALL(id), [&](int i, int j) { return e[i] < e[j]; });
  FOR(i, 0, n) {
    int j = i;
    while (j < n && e[id[i]] == e[id[j]]) j++;
    FOR(k, i, j) {
      for (auto v : g[id[k]]) {
        if (e[id[k]] >= e[v]) dsu.join(id[k], v);
      }
    }
    FOR(k, i, j) { ans[id[k]] = dsu.size(id[k]); }
    i = j - 1;
  }
  for (auto x : ans) cout << x << ENDL;
  return 0;
}