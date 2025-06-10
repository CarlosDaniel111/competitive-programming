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

constexpr ll INF = 1e15;

struct Node {
  ll sum, mx1, mx2, mxcnt, mn1, mn2, mncnt, lazy;

  Node(ll v)
      : sum(v),
        mx1(v),
        mn1(v),
        mxcnt(1),
        mncnt(1),
        mx2(-INF),
        mn2(INF),
        lazy(0) {}
  Node() : lazy(0) {}
};

struct STree {
#define ls (k << 1) + 1
#define rs (k << 1) + 2
#define lp ls, s, m
#define rp rs, m, e

  int n;
  vector<Node> st;

  STree(int n) : n(n), st((n << 2) + 5) {}

  void merge(Node &curr, Node l, Node r) {
    curr.sum = l.sum + r.sum;

    if (l.mx1 == r.mx1) {
      curr.mx1 = l.mx1;
      curr.mxcnt = l.mxcnt + r.mxcnt;
      curr.mx2 = max(l.mx2, r.mx2);
    } else {
      if (l.mx1 > r.mx1) {
        curr.mx1 = l.mx1;
        curr.mxcnt = l.mxcnt;
        curr.mx2 = max(l.mx2, r.mx1);
      } else {
        curr.mx1 = r.mx1;
        curr.mxcnt = r.mxcnt;
        curr.mx2 = max(r.mx2, l.mx1);
      }
    }

    if (l.mn1 == r.mn1) {
      curr.mn1 = l.mn1;
      curr.mncnt = l.mncnt + r.mncnt;
      curr.mn2 = min(l.mn2, r.mn2);
    } else {
      if (l.mn1 < r.mn1) {
        curr.mn1 = l.mn1;
        curr.mncnt = l.mncnt;
        curr.mn2 = min(l.mn2, r.mn1);
      } else {
        curr.mn1 = r.mn1;
        curr.mncnt = r.mncnt;
        curr.mn2 = min(r.mn2, l.mn1);
      }
    }
  }

  void pull(int k) { merge(st[k], st[ls], st[rs]); }

  void applyAdd(int k, int s, int e, ll v) {
    st[k].sum += (e - s) * v;
    st[k].mx1 += v;
    if (st[k].mx2 != -INF) st[k].mx2 += v;
    st[k].mn1 += v;
    if (st[k].mn2 != INF) st[k].mn2 += v;
    st[k].lazy += v;
  }

  void applyChMin(int k, int s, int e, ll v) {
    if (v >= st[k].mx1) return;
    st[k].sum -= st[k].mx1 * st[k].mxcnt;
    st[k].mx1 = v;
    st[k].sum += st[k].mx1 * st[k].mxcnt;

    if (v < st[k].mn1)
      st[k].mn1 = v;
    else if (v < st[k].mn2)
      st[k].mn2 = v;
  }

  void applyChMax(int k, int s, int e, ll v) {
    if (v <= st[k].mn1) return;
    st[k].sum -= st[k].mn1 * st[k].mncnt;
    st[k].mn1 = v;
    st[k].sum += st[k].mn1 * st[k].mncnt;

    if (v > st[k].mx1)
      st[k].mx1 = v;
    else if (v > st[k].mx2)
      st[k].mx2 = v;
  }

  void push(int k, int s, int e) {
    int m = (s + e) >> 1;
    if (st[k].lazy) {
      applyAdd(lp, st[k].lazy);
      applyAdd(rp, st[k].lazy);
      st[k].lazy = 0;
    }

    applyChMin(lp, st[k].mx1);
    applyChMin(rp, st[k].mx1);

    applyChMax(lp, st[k].mn1);
    applyChMax(rp, st[k].mn1);
  }

  void build(int k, int s, int e, vector<ll> &a) {
    if (s + 1 == e) {
      st[k] = Node(a[s]);
      return;
    }
    int m = (s + e) >> 1;
    build(lp, a);
    build(rp, a);
    pull(k);
  }

  ll query(int k, int s, int e, int a, int b) {
    if (a <= s && e <= b) return st[k].sum;
    push(k, s, e);
    int m = (s + e) >> 1;
    if (a >= m) return query(rp, a, b);
    if (b <= m) return query(lp, a, b);
    return query(lp, a, b) + query(rp, a, b);
  }

  void updAdd(int k, int s, int e, int a, int b, ll v) {
    if (a <= s && e <= b) {
      applyAdd(k, s, e, v);
      return;
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (a < m) updAdd(lp, a, b, v);
    if (b > m) updAdd(rp, a, b, v);
    pull(k);
  }

  void updChMin(int k, int s, int e, int a, int b, ll v) {
    if (v >= st[k].mx1) return;
    if (a <= s && e <= b && v > st[k].mx2) {
      applyChMin(k, s, e, v);
      return;
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (a < m) updChMin(lp, a, b, v);
    if (b > m) updChMin(rp, a, b, v);
    pull(k);
  }

  void updChMax(int k, int s, int e, int a, int b, ll v) {
    if (v <= st[k].mn1) return;
    if (a <= s && e <= b && v < st[k].mn2) {
      applyChMax(k, s, e, v);
      return;
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (a < m) updChMax(lp, a, b, v);
    if (b > m) updChMax(rp, a, b, v);
    pull(k);
  }

  void build(vector<ll> &a) { build(0, 0, n, a); }
  ll query(int a, int b) { return query(0, 0, n, a, b); }
  void updAdd(int a, int b, ll v) { updAdd(0, 0, n, a, b, v); }
  void updChMin(int a, int b, ll v) { updChMin(0, 0, n, a, b, v); }
  void updChMax(int a, int b, ll v) { updChMax(0, 0, n, a, b, v); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  STree st(n);
  FOR(i, 0, n) cin >> a[i];
  st.build(a);
  while (q--) {
    ll opc, l, r, b;
    cin >> opc;
    if (opc == 0) {
      cin >> l >> r >> b;
      st.updChMin(l, r, b);
    } else if (opc == 1) {
      cin >> l >> r >> b;
      st.updChMax(l, r, b);
    } else if (opc == 2) {
      cin >> l >> r >> b;
      st.updAdd(l, r, b);
    } else {
      cin >> l >> r;
      cout << st.query(l, r) << ENDL;
    }
  }

  return 0;
}