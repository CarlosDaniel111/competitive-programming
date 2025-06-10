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
  ll sum, pref, suff, ans;
  Data(ll v) {
    sum = v;
    pref = suff = ans = max(0ll, v);
  }
  Data() {}
};

struct STree {
#define ls (k << 1) + 1
#define rs (k << 1) + 2
#define lp ls, s, m
#define rp rs, m, e

  int n;
  vector<Data> st;
  STree(int n) : n(n), st((n << 2) + 5) {}

  Data merge(Data x, Data y) {
    Data curr;
    curr.sum = x.sum + y.sum;
    curr.pref = max(x.pref, x.sum + y.pref);
    curr.suff = max(y.suff, y.sum + x.suff);
    curr.ans = max({x.ans, y.ans, x.suff + y.pref});
    return curr;
  }

  void build(int k, int s, int e, vi &a) {
    if (s + 1 == e) {
      st[k] = Data(a[s]);
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

  void build(vi &a) { build(0, 0, n, a); }
  void upd(int i, int v) { upd(0, 0, n, i, v); }
  ll get() { return st[0].ans; }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  STree st(n);
  st.build(a);
  cout << st.get() << ENDL;
  while (q--) {
    int i, v;
    cin >> i >> v;
    st.upd(i, v);
    cout << st.get() << ENDL;
  }

  return 0;
}