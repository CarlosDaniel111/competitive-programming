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
  vector<ll> st;
  STree(int n) : n(n), st((n << 2) + 5) {}

  ll merge(ll x, ll y) { return x + y; }

  void build(int k, int s, int e, vi &a) {
    if (s + 1 == e) {
      st[k] = a[s];
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
      st[k] = v;
      return;
    }
    int m = (s + e) >> 1;
    upd(lp, i, v);
    upd(rp, i, v);
    st[k] = merge(st[ls], st[rs]);
  }

  ll query(int k, int s, int e, int a, int b) {
    if (b <= s or e <= a) return 0;
    if (a <= s && e <= b) return st[k];
    int m = (s + e) >> 1;
    return merge(query(lp, a, b), query(rp, a, b));
  }

  void build(vi &a) { build(0, 0, n, a); }
  void upd(int i, int v) { upd(0, 0, n, i, v); }
  ll query(int a, int b) { return query(0, 0, n, a, b); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vi a(n, 0), b(n, 0);
  FOR(i, 0, n) {
    if (i & 1)
      cin >> b[i];
    else
      cin >> a[i];
  }
  STree st1(n), st2(n);
  st1.build(a);
  st2.build(b);
  int q;
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op == 0) {
      int i, v;
      cin >> i >> v;
      i--;
      if (i & 1)
        st2.upd(i, v);
      else
        st1.upd(i, v);
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      int q1 = st1.query(l, r);
      int q2 = st2.query(l, r);
      if (l & 1) {
        cout << q2 - q1 << ENDL;
      } else {
        cout << q1 - q2 << ENDL;
      }
    }
  }

  return 0;
}