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

struct STree {
#define ls 2 * v + 1
#define rs 2 * v + 2
#define lp ls, tl, tm
#define rp rs, tm, tr
#define NEUT 0

  int n;
  vector<int> st;

  STree(int n) : n(n), st(4 * n) {}

  int query(int v, int tl, int tr, int l, int r) {
    if (tr <= l || r <= tl) return NEUT;
    if (l <= tl && tr <= r) return st[v];
    int tm = (tl + tr) / 2;
    return query(lp, l, r) + query(rp, l, r);
  }

  void upd(int v, int tl, int tr, int i, int val) {
    if (tl + 1 == tr) {
      st[v] = val;
      return;
    }
    int tm = (tl + tr) / 2;
    if (i < tm)
      upd(lp, i, val);
    else
      upd(rp, i, val);
    st[v] = st[ls] + st[rs];
  }

  int query(int l, int r) { return query(0, 0, n, l, r); }
  void upd(int i, int val) { upd(0, 0, n, i, val); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  map<int, vi> know;
  FOR(i, 0, n) {
    int x;
    cin >> x;
    know[x].pb(i);
  }

  vector<vi> g(n);
  FOR(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  int c = 0;
  vi in(n), out(n);
  auto dfs = [&](auto self, int u, int p) -> void {
    in[u] = c++;
    for (auto v : g[u]) {
      if (v == p) continue;
      self(self, v, u);
    }
    out[u] = c++;
  };

  dfs(dfs, 0, -1);
  map<int, vector<pi>> queries;
  FOR(i, 0, q) {
    int x, k;
    cin >> x >> k;
    x--;
    queries[k].pb({x, i});
  }
  STree st(c + 10);
  vi ans(q);
  for (auto [x, people] : know) {
    for (auto id : people) st.upd(in[id], 1);

    for (auto [k, idx] : queries[x]) {
      ans[idx] = st.query(in[k], out[k]);
    }

    for (auto id : people) st.upd(in[id], 0);
  }
  for (auto x : ans) cout << x << ENDL;

  return 0;
}