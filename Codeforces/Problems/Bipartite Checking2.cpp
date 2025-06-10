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
  vector<int> e;
  vector<pi> st;
  void init(int n) { e = vi(n, -1); }
  int size(int x) { return -e[get(x)]; }
  int get(int x) { return e[x] < 0 ? x : get(e[x]); }
  int time() { return st.size(); }
  void rollback(int t) {
    for (int i = time(); i-- > t;) e[st[i].first] = st[i].second;
    st.resize(t);
  }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    st.push_back({a, e[a]});
    st.push_back({b, e[b]});
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

bool ans = 1;
int n;
vi vis;

void solve(int L, int R, vector<iiii> &ranges, RollbackDSU &dsu) {
  int prev = dsu.time();
  int mid = (L + R) >> 1;
  vector<iiii> left, right;
  for (auto [u, v, l, r] : ranges) {
    if (l <= L && R <= r) {
      // cout << "se mete " << u << " " << v << ENDL;
      if (dsu.get(u) == dsu.get(v)) {
        dsu.rollback(prev);
        return;
      }
      dsu.join(dsu.get(u), dsu.get(v + n));
      dsu.join(dsu.get(v), dsu.get(u + n));
    } else {
      if (l <= mid) left.pb({u, v, l, r});
      if (r > mid) right.pb({u, v, l, r});
    }
  }
  if (L == R) {
    vis[L] = 1;
  } else {
    solve(L, mid, left, dsu);
    solve(mid + 1, R, right, dsu);
  }
  dsu.rollback(prev);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int m;
  cin >> n >> m;
  RollbackDSU dsu;
  dsu.init(2 * n + 5);
  vector<iiii> ranges;
  vis.assign(m + 5, 0);
  map<pi, int> mp;
  FOR(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    //  if (u > v) swap(u, v);
    if (mp.count({u, v})) {
      ranges.pb({u, v, mp[{u, v}], i - 1});
      mp.erase({u, v});
    } else {
      mp[{u, v}] = i;
    }
  }
  for (auto [edge, pos] : mp) ranges.pb({edge.first, edge.second, pos, m - 1});
  solve(0, m - 1, ranges, dsu);
  FOR(i, 0, m) {
    if (vis[i])
      cout << "YES" << ENDL;
    else
      cout << "NO" << ENDL;
  }

  return 0;
}