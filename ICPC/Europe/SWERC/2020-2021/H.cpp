#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

#define oper(a, b) (a + b)
#define NEUT 0
struct STree {  // persistent segment tree for min over integers
  vector<int> st, L, R;
  int n, sz, rt;
  STree(int n) : st(1, NEUT), L(1, 0), R(1, 0), n(n), rt(0), sz(1) {}
  int new_node(int v, int l = 0, int r = 0) {
    int ks = SZ(st);
    st.pb(v);
    L.pb(l);
    R.pb(r);
    return ks;
  }
  int init(int s, int e, vi a) {  // not necessary in most cases
    if (s + 1 == e) return new_node(a[s]);
    int m = (s + e) / 2, l = init(s, m, a), r = init(m, e, a);
    return new_node(oper(st[l], st[r]), l, r);
  }
  int upd(int k, int s, int e, int p, int v) {
    int ks = new_node(st[k], L[k], R[k]);
    if (s + 1 == e) {
      st[ks] += v;
      return ks;
    }
    int m = (s + e) / 2, ps;
    if (p < m)
      ps = upd(L[ks], s, m, p, v), L[ks] = ps;
    else
      ps = upd(R[ks], m, e, p, v), R[ks] = ps;
    st[ks] = oper(st[L[ks]], st[R[ks]]);
    return ks;
  }
  int query(int k, int s, int e, int a, int b) {
    if (e <= a || b <= s) return NEUT;
    if (a <= s && e <= b) return st[k];
    int m = (s + e) / 2;
    return oper(query(L[k], s, m, a, b), query(R[k], m, e, a, b));
  }
  int init(vi a) { return init(0, n, a); }
  int upd(int k, int p, int v) { return rt = upd(k, 0, n, p, v); }
  int upd(int p, int v) { return upd(rt, p, v); }                   // update on last root, returns new root
  int query(int k, int a, int b) { return query(k, 0, n, a, b); };  // [a, b)
  // k -> starting root
};

signed main() {
  int n;
  cin >> n;
  getchar();

  vi root;

  STree st(n);
  vi id(n + 1, 0);

  FOR(i, 0, n) {
    for (char c = 0; c != '\n'; c = getchar()) {
      if (c == '+' || c == '-') {
        int x;
        scanf("%d", &x);
        if (c == '+') {
          root.pb(st.upd(x, 1));
        } else {
          root.pb(st.upd(x, -1));
        }
      }
    }
    id[i + 1] = root.back();
  }
  int ans = 0;
  FOR(i, 0, n) {
    int d;
    cin >> d;
    ans = (ans + st.query(id[d], ans, n)) % n;
  }
  cout << ans << ENDL;

  return 0;
}