#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using iiii = tuple<int, int, int, int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

struct RollbackDSU {
  int comps;
  vector<int> p, r;
  vector<tuple<int, int, bool>> st;

  RollbackDSU(int n) : comps(n), p(n, -1), r(n, 1) {}

  void rollback(int k) {
    while (k--) {
      auto [u, v, b] = st.back();
      st.pop_back();
      if (b) --r[v];
      p[u] = -1;
      ++comps;
    }
  }

  int get(int x) { return p[x] == -1 ? x : get(p[x]); }

  bool join(int u, int v) {
    u = get(u), v = get(v);
    if (u == v) return false;
    if (r[u] > r[v]) swap(u, v);
    bool b = false;
    if (r[v] == r[u]) {
      ++r[v];
      b = true;
    }
    st.emplace_back(u, v, b);
    p[u] = v;
    --comps;
    return true;
  }
};

void solve(int L, int R, vector<iiii> &edges, RollbackDSU &dsu, vi &ans) {
  int prev = dsu.st.size();
  for (auto [u, v, l, r] : edges) {
    if (l <= L && R <= r) dsu.join(u, v);
  }
  if (L == R) {
    ans[L] = dsu.comps;
    dsu.rollback(dsu.st.size() - prev);
    return;
  }
  int mid = (L + R) >> 1;
  vector<iiii> left, right;
  for (auto [u, v, l, r] : edges) {
    if (!(l <= L && R <= r)) {
      if (l <= mid) left.pb({u, v, l, r});
      if (r > mid) right.pb({u, v, l, r});
    }
  }
  solve(L, mid, left, dsu, ans);
  solve(mid + 1, R, right, dsu, ans);
  dsu.rollback(dsu.st.size() - prev);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  freopen("disconnected.in", "r", stdin);
  freopen("disconnected.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  RollbackDSU dsu(n);
  vi last(m, 0);
  vector<pi> edges(m);

  FOR(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (u > v) swap(u, v);
    edges[i] = {u, v};
  }
  int k;
  cin >> k;
  vi ans(k + 2);
  vector<iiii> edg;
  FOR(i, 1, k + 1) {
    int c;
    cin >> c;
    while (c--) {
      int x;
      cin >> x;
      x--;
      edg.pb({edges[x].first, edges[x].second, last[x], i - 1});
      last[x] = i + 1;
    }
  }
  FOR(i, 0, m) { edg.pb({edges[i].first, edges[i].second, last[i], k + 1}); }
  solve(0, k + 1, edg, dsu, ans);
  FOR(i, 1, k + 1) {
    if (ans[i] == 1) {
      cout << "Connected" << ENDL;
    } else {
      cout << "Disconnected" << ENDL;
    }
  }

  return 0;
}