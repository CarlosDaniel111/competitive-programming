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

struct node {
  char l, r;
  int c;
};

struct STree {
#define ls 2 * v + 1
#define rs 2 * v + 2
#define lp ls, tl, tm
#define rp rs, tm, tr
#define NEUT 0

  int n;
  vector<node> st;

  STree(int n) : n(n), st(4 * n) {}

  node merge(node a, node b) {
    int curr = a.c + b.c;
    if (a.r == b.l) curr--;
    return {a.l, b.r, curr};
  }

  void build(int v, int tl, int tr, string &a) {
    if (tl + 1 == tr) {
      st[v].l = a[tl];
      st[v].r = a[tl];
      st[v].c = 1;
      return;
    }
    int tm = (tl + tr) / 2;
    build(lp, a);
    build(rp, a);
    st[v] = merge(st[ls], st[rs]);
  }

  node query(int v, int tl, int tr, int l, int r) {
    if (tr <= l || r <= tl) return {'z', 'y', 0};
    if (l <= tl && tr <= r) return st[v];
    int tm = (tl + tr) / 2;
    return merge(query(lp, l, r), query(rp, l, r));
  }

  void upd(int v, int tl, int tr, int i, char val) {
    if (tl + 1 == tr) {
      st[v].l = val;
      st[v].r = val;
      return;
    }
    int tm = (tl + tr) / 2;
    if (i < tm)
      upd(lp, i, val);
    else
      upd(rp, i, val);
    st[v] = merge(st[ls], st[rs]);
  }

  node query(int l, int r) { return query(0, 0, n, l, r); }
  void upd(int i, char val) { upd(0, 0, n, i, val); }
  void build(string &s) { build(0, 0, n, s); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  STree st(n);
  string s;
  cin >> s;
  st.build(s);

  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r;
      cin >> l >> r;
      l--;
      cout << st.query(l, r).c << ENDL;
    } else {
      int i;
      char c;
      cin >> i >> c;
      i--;
      st.upd(i, c);
    }
  }

  return 0;
}