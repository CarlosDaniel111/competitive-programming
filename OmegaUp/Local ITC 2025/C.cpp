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
  vector<int> st, lazy;

  STree(int n) : n(n), st((n << 2) + 5), lazy((n << 2) + 5) {}

  int merge(int x, int y) { return x + y; }

  void pull(int k) { st[k] = merge(st[ls], st[rs]); }

  void apply(int k, int s, int e) {
    st[k] = (e - s) - st[k];
    lazy[k] ^= 1;
  }

  void push(int k, int s, int e) {
    if (lazy[k]) {
      int m = (s + e) >> 1;
      apply(lp);
      apply(rp);
      lazy[k] = 0;
    }
  }

  void build(int k, int s, int e, vector<int>& a) {
    if (s + 1 == e) {
      st[k] = a[s];
      return;
    }
    int m = (s + e) >> 1;
    build(lp, a);
    build(rp, a);
    pull(k);
  }

  int query(int k, int s, int e, int a, int b) {
    if (a <= s && e <= b) {
      return st[k];
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (a >= m) {
      return query(rp, a, b);
    }
    if (b <= m) {
      return query(lp, a, b);
    }
    return merge(query(lp, a, b), query(rp, a, b));
  }

  void upd(int k, int s, int e, int a, int b) {
    if (a <= s && e <= b) {
      apply(k, s, e);
      return;
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (a < m) {
      upd(lp, a, b);
    }
    if (b > m) {
      upd(rp, a, b);
    }
    pull(k);
  }

  int query(int a, int b) { return query(0, 0, n, a, b); }
  void upd(int a, int b) { upd(0, 0, n, a, b); }
  void build(vector<int>& a) { build(0, 0, n, a); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  STree st(n + 5);
  while (m--) {
    int k, a, b;
    cin >> k >> a >> b;
    if (k == 0) {
      st.upd(a - 1, b);
    } else {
      cout << st.query(a - 1, b) << ENDL;
    }
  }

  return 0;
}