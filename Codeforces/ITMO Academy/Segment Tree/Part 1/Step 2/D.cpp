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

  ll merge(ll x, ll y) { return max(x, y); }

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

  int get(int k, int s, int e, int l, int v) {
    if (s + 1 == e) return ((st[k] >= v && s >= l) ? s : -1);
    int m = (s + e) >> 1;
    if (st[ls] >= v && m > l) {
      int left = get(lp, l, v);
      if (left == -1)
        return get(rp, l, v);
      else
        return left;
    } else
      return get(rp, l, v);
  }

  void build(vi &a) { build(0, 0, n, a); }
  void upd(int i, int v) { upd(0, 0, n, i, v); }
  int get(int l, int v) { return get(0, 0, n, l, v); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  STree st(n);
  st.build(a);
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int i, v;
      cin >> i >> v;
      st.upd(i, v);
    } else {
      int x, l;
      cin >> x >> l;
      cout << st.get(l, x) << ENDL;
    }
  }

  return 0;
}