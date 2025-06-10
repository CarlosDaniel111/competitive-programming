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
#define ls (k << 1) + 1
#define rs (k << 1) + 2
#define lp ls, s, m
#define rp rs, m, e

  int n;
  vector<pi> st;
  STree(int n) : n(n), st((n << 2) + 5) {}

  pi merge(pi x, pi y) {
    if (x.first == y.first)
      return {x.first, x.second + y.second};
    else if (x.first < y.first)
      return x;
    else
      return y;
  }

  void build(int k, int s, int e, vi &a) {
    if (s + 1 == e) {
      st[k] = {a[s], 1};
      return;
    }
    int m = (s + e) >> 1;
    build(lp, a);
    build(rp, a);
    st[k] = merge(st[ls], st[rs]);
  }

  void upd(int k, int s, int e, int i, int v) {
    if (e <= i or s > i) return;
    if (s + 1 == e) {
      st[k] = {v, 1};
      return;
    }
    int m = (s + e) >> 1;
    upd(lp, i, v);
    upd(rp, i, v);
    st[k] = merge(st[ls], st[rs]);
  }

  pi query(int k, int s, int e, int a, int b) {
    if (b <= s or e <= a) return {1e9 + 5, 1};
    if (a <= s && e <= b) return st[k];
    int m = (s + e) >> 1;
    return merge(query(lp, a, b), query(rp, a, b));
  }

  void build(vi &a) { build(0, 0, n, a); }
  void upd(int i, int v) { upd(0, 0, n, i, v); }
  pi query(int a, int b) { return query(0, 0, n, a, b); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  STree st(n);
  st.build(a);
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int i, v;
      cin >> i >> v;
      st.upd(i, v);
    } else {
      int l, r;
      cin >> l >> r;
      auto [mn, cnt] = st.query(l, r);
      cout << mn << " " << cnt << ENDL;
    }
  }

  return 0;
}