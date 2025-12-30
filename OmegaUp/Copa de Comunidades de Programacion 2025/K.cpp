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

  void build(int v, int tl, int tr, vi &a) {
    if (tl + 1 == tr) {
      st[v] = a[tl];
      return;
    }
    int tm = (tl + tr) / 2;
    build(lp, a);
    build(rp, a);
    st[v] = max(st[ls], st[rs]);
  }

  int query(int v, int tl, int tr, int l, int r) {
    if (tr <= l || r <= tl) return NEUT;
    if (l <= tl && tr <= r) return st[v];
    int tm = (tl + tr) / 2;
    return max(query(lp, l, r), query(rp, l, r));
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
    st[v] = max(st[ls], st[rs]);
  }

  int query(int l, int r) { return query(0, 0, n, l, r); }
  void upd(int i, int val) { upd(0, 0, n, i, val); }
  void build(vi &a) { build(0, 0, n, a); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];

  STree st(n);
  st.build(a);
  FOR(i, 0, n - k + 1) { cout << st.query(i, i + k) << " "; }
  cout << ENDL;

  return 0;
}