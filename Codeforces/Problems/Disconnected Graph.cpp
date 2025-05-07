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
constexpr int N = 3e5 + 9;

struct RollbackDSU {
  int comps;
  vector<int> p, r;
  vector<tuple<int, int, bool>> st;

  void init(int n) {
    comps = n;
    p.assign(n, -1);
    r.assign(n, 1);
    st.clear();
  }

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

vector<vector<pi>> t;
RollbackDSU dsu;
vi ans;

void update(int k, int s, int e, int a, int b, pi edge) {
  if (s > b || e < a) return;
  if (s >= a && e <= b) {
    t[k].pb(edge);
    return;
  }
  int mid = (s + e) >> 1;
  update((k << 1) + 1, s, mid, a, b, edge);
  update((k << 1) + 2, mid + 1, e, a, b, edge);
}

void dfs(int k, int l, int r) {
  if (l > r) return;
  int prev = dsu.st.size();
  for (auto [u, v] : t[k]) dsu.join(u, v);

  if (l == r) {
    ans[l] = dsu.comps;
    dsu.rollback(dsu.st.size() - prev);
    return;
  }
  int mid = (l + r) >> 1;
  dfs((k << 1) + 1, l, mid);
  dfs((k << 1) + 2, mid + 1, r);
  dsu.rollback(dsu.st.size() - prev);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  freopen("disconnected.in", "r", stdin);
  freopen("disconnected.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  dsu.init(n);
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
  ans.resize(k + 5);
  t.resize(N * 4);
  FOR(i, 1, k + 1) {
    int c;
    cin >> c;
    while (c--) {
      int x;
      cin >> x;
      x--;
      update(0, 0, k + 1, last[x], i - 1, edges[x]);
      last[x] = i + 1;
    }
  }
  FOR(i, 0, m) { update(0, 0, k + 1, last[i], k + 1, edges[i]); }
  dfs(0, 0, k + 1);
  FOR(i, 1, k + 1) {
    if (ans[i] == 1) {
      cout << "Connected" << ENDL;
    } else {
      cout << "Disconnected" << ENDL;
    }
  }

  return 0;
}