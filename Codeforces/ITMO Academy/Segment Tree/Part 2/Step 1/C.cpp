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
  STree(int n) : n(n), st((n << 2) + 5, 0), lazy((n << 2) + 5, -1) {}

  ll merge(ll x, ll y) { return x + y; }

  void apply(int k, int s, int e, ll v) {
    st[k] = (e - s) * v;
    lazy[k] = v;
  }

  void push(int k, int s, int e) {
    if (lazy[k] != -1) {
      int m = (s + e) >> 1;
      apply(lp, lazy[k]);
      apply(rp, lazy[k]);
      lazy[k] = -1;
    }
  }

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

  void set(int k, int s, int e, int a, int b, ll v) {
    if (s >= b || e <= a) return;
    if (a <= s && e <= b) {
      apply(k, s, e, v);
      return;
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    set(lp, a, b, v);
    set(rp, a, b, v);
    st[k] = merge(st[ls], st[rs]);
  }

  ll query(int k, int s, int e, int a, int b) {
    if (b <= s or e <= a) return 0;
    if (a <= s && e <= b) return st[k];
    push(k, s, e);
    int m = (s + e) >> 1;
    return merge(query(lp, a, b), query(rp, a, b));
  }

  ll query(int a, int b) { return query(0, 0, n, a, b); }
  void set(int a, int b, int v) { set(0, 0, n, a, b, v); }
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
      st.set(l, r, v);
    } else {
      int pos;
      cin >> pos;
      cout << st.query(pos, pos + 1) << ENDL;
    }
  }

  return 0;
}