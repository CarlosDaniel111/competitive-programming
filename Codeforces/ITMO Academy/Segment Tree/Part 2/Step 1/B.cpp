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
  vector<ll> st, lazy;
  STree(int n) : n(n), st((n << 2) + 5, 0), lazy((n << 2) + 5, 0) {}

  ll merge(ll x, ll y) { return max(x, y); }

  void build(int k, int s, int e, vi& a) {
    if (s + 1 == e) {
      st[k] = a[s];
      return;
    }
    int m = (s + e) >> 1;
    build(lp, a);
    build(rp, a);
    st[k] = merge(st[ls], st[rs]);
  }

  void upd(int k, int s, int e, int a, int b, ll v) {
    if (s >= b || e <= a) return;
    if (a <= s && e <= b) {
      st[k] = merge(st[k], v);
      return;
    }
    int m = (s + e) >> 1;
    upd(lp, a, b, v);
    upd(rp, a, b, v);
  }

  ll get(int k, int s, int e, int i) {
    if (s + 1 == e) return st[k];
    int m = (s + e) >> 1;
    if (i < m)
      return max(st[k], get(lp, i));
    else
      return max(st[k], get(rp, i));
  }

  ll get(int i) { return get(0, 0, n, i); }
  void upd(int a, int b, int v) { upd(0, 0, n, a, b, v); }
  void build(vector<int>& a) { build(0, 0, n, a); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  STree st(n);
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      ll l, r, v;
      cin >> l >> r >> v;
      st.upd(l, r, v);
    } else {
      int pos;
      cin >> pos;
      cout << st.get(pos) << ENDL;
    }
  }

  return 0;
}