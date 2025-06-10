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

struct Data {
  ll sum, mx;
};

struct STree {
#define ls (k << 1) + 1
#define rs (k << 1) + 2
#define lp ls, s, m
#define rp rs, m, e

  int n;
  vector<Data> st;

  STree(int n) : n(n), st((n << 2) + 5) {}

  Data merge(Data x, Data y) { return {x.sum + y.sum, max(x.mx, y.mx)}; }

  void pull(int k) { st[k] = merge(st[ls], st[rs]); }

  void build(int k, int s, int e, vector<int>& a) {
    if (s + 1 == e) {
      st[k] = {a[s], a[s]};
      return;
    }
    int m = (s + e) >> 1;
    build(lp, a);
    build(rp, a);
    pull(k);
  }

  Data query(int k, int s, int e, int a, int b) {
    if (a <= s && e <= b) return st[k];
    int m = (s + e) >> 1;
    if (a >= m) return query(rp, a, b);
    if (b <= m) return query(lp, a, b);
    return merge(query(lp, a, b), query(rp, a, b));
  }

  void updMod(int k, int s, int e, int a, int b, int v) {
    if (st[k].mx < v) return;
    if (s + 1 == e) {
      st[k].sum %= v;
      st[k].mx %= v;
      return;
    }
    int m = (s + e) >> 1;
    if (a < m) {
      updMod(lp, a, b, v);
    }
    if (b > m) {
      updMod(rp, a, b, v);
    }
    pull(k);
  }

  void upd(int k, int s, int e, int i, int v) {
    if (s + 1 == e) {
      st[k] = {v, v};
      return;
    }
    int m = (s + e) >> 1;
    if (i < m) {
      upd(lp, i, v);
    } else {
      upd(rp, i, v);
    }
    pull(k);
  }

  ll query(int a, int b) { return query(0, 0, n, a, b).sum; }
  void updMod(int a, int b, int v) { updMod(0, 0, n, a, b, v); }
  void upd(int i, int v) { upd(0, 0, n, i, v); }
  void build(vector<int>& a) { build(0, 0, n, a); }
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
    int opc;
    cin >> opc;
    if (opc == 1) {
      int l, r;
      cin >> l >> r;
      cout << st.query(l - 1, r) << ENDL;
    } else if (opc == 2) {
      int l, r, x;
      cin >> l >> r >> x;
      st.updMod(l - 1, r, x);
    } else {
      int k, x;
      cin >> k >> x;
      k--;
      st.upd(k, x);
    }
  }

  return 0;
}