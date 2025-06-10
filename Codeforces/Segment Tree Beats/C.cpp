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
  ll res, mx1, mx2, mxcnt;

  Node() : res(0), mx1(INF), mxcnt(0), mx2(-INF) {}
};

struct STree {
#define ls (k << 1) + 1
#define rs (k << 1) + 2
#define lp ls, s, m
#define rp rs, m, e

  int n;
  vector<Node> st[2];

  STree(int n) : n(n) {
    st[0].resize((n << 2) + 5);
    st[1].resize((n << 2) + 5);
  }

  void merge(Node &curr, Node l, Node r) {
    curr.res = l.res + r.res;

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
  }

  void pull(int k, bool op) { merge(st[op][k], st[op][ls], st[op][rs]); }

  void applyChMin(int k, int s, int e, ll v, bool op) {
    if (v >= st[op][k].mx1) return;
    st[op][k].res -= (st[op][k].mx1 - v) * st[op][k].mxcnt;
    st[op][k].mx1 = v;
  }

  void push(int k, int s, int e, bool op) {
    int m = (s + e) >> 1;
    applyChMin(lp, st[op][k].mx1, op);
    applyChMin(rp, st[op][k].mx1, op);
  }

  ll query(int k, int s, int e, int a, int b) {
    if (a <= s && e <= b) return st[0][k].res + st[1][k].res;
    push(k, s, e, 0);
    push(k, s, e, 1);
    int m = (s + e) >> 1;
    if (a >= m) return query(rp, a, b);
    if (b <= m) return query(lp, a, b);
    return query(lp, a, b) + query(rp, a, b);
  }

  void updChMin(int k, int s, int e, int a, int b, ll v, bool op) {
    if (v >= st[op][k].mx1) return;
    if (a <= s && e <= b && v > st[op][k].mx2) {
      applyChMin(k, s, e, v, op);
      return;
    }
    push(k, s, e, 0);
    push(k, s, e, 1);
    int m = (s + e) >> 1;
    if (a < m) updChMin(lp, a, b, v, op);
    if (b > m) updChMin(rp, a, b, v, op);
    pull(k, 0);
    pull(k, 1);
  }

  void firstTime(int k, int s, int e, int a, int b, ll v, bool op) {
    if (st[op][k].mx1 != INF) return;
    if (s + 1 == e) {
      st[op][k].mx1 = v;
      if (st[!op][k].mx1 != INF) {
        st[op][k].mxcnt = 1;
        st[!op][k].mxcnt = 1;
        st[op][k].res = v;
        st[!op][k].res = st[!op][k].mx1;
      }
      return;
    }
    push(k, s, e, 0);
    push(k, s, e, 1);
    int m = (s + e) >> 1;
    if (a < m) firstTime(lp, a, b, v, op);
    if (b > m) firstTime(rp, a, b, v, op);
    pull(k, 0);
    pull(k, 1);
  }
  ll query(int a, int b) { return query(0, 0, n, a, b); }
  void updChMin(int a, int b, ll v, bool op) { updChMin(0, 0, n, a, b, v, op); }
  void firstTime(int a, int b, ll v, bool op) {
    firstTime(0, 0, n, a, b, v, op);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int q;
  cin >> q;
  STree st(1e5 + 5);
  while (q--) {
    int opc, l, r, k;
    cin >> opc >> l >> r;
    l--, r--;
    if (opc == 1) {
      cin >> k;
      st.firstTime(l, r, abs(k), k > 0);
      st.updChMin(l, r, abs(k), k > 0);
    } else {
      cout << st.query(l, r) << ENDL;
    }
  }

  return 0;
}