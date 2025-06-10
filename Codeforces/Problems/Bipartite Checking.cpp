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

struct DSU {
  bool bip;
  vector<int> p, d, r;
  vector<tuple<int, int, bool, bool>> st;
  DSU(int n) : bip(true), p(n, -1), d(n, 0), r(n, 1), st() {}

  void rollback(int k) {
    while (k--) {
      auto [u, v, inc, cycle] = st.back();
      st.pop_back();
      if (cycle) {
        bip = true;
        continue;
      }
      p[u] = -1;
      d[u] = 0;
      if (inc) {
        --r[v];
      }
    }
  }

  int get(int u) { return p[u] == -1 ? u : get(p[u]); }

  int dist(int u) { return p[u] == -1 ? 0 : dist(p[u]) + d[u]; }

  bool join(int u, int v) {
    int du = dist(u), dv = dist(v);
    u = get(u), v = get(v);
    if (u == v) {
      if ((du & 1) != (dv & 1) || !bip) {
        return false;
      }
      bip = false;
      st.emplace_back(u, v, false, true);
      return true;
    }
    if (r[u] > r[v]) {
      swap(u, v);
    }
    bool inc = false;
    if (r[u] == r[v]) {
      ++r[v];
      inc = true;
    }
    p[u] = v;
    d[u] = du + dv + 1;
    st.emplace_back(u, v, inc, false);
    return true;
  }
};

bool ans;
int n;

void solve(int L, int R, vector<iiii> &ranges, DSU &dsu) {
  int joins = 0;
  bool prevAns = ans;
  int mid = (L + R) >> 1;
  vector<iiii> left, right;
  for (auto [u, v, l, r] : ranges) {
    if (l <= L && R <= r) {
      joins += dsu.join(u, v);
    } else {
      if (l <= mid) left.pb({u, v, l, r});
      if (r > mid) right.pb({u, v, l, r});
    }
  }
  if (L == R) {
    cout << (dsu.bip ? "YES" : "NO") << '\n';
    dsu.rollback(joins);
    return;
  }
  solve(L, mid, left, dsu);
  solve(mid + 1, R, right, dsu);
  dsu.rollback(joins);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int m;
  cin >> n >> m;
  DSU dsu(n);
  vector<iiii> ranges;
  map<pi, int> mp;
  FOR(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (u > v) swap(u, v);
    if (mp.count({u, v})) {
      ranges.pb({u, v, mp[{u, v}], i - 1});
      mp.erase({u, v});
    } else {
      mp[{u, v}] = i;
    }
  }
  for (auto [edge, pos] : mp) ranges.pb({edge.first, edge.second, pos, m});
  ans = 1;
  solve(0, m - 1, ranges, dsu);

  return 0;
}