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
  vector<int> st;

  STree(int n) : n(n), st((n << 2) + 5) { build(0, 0, n); }

  int merge(int x, int y) { return x + y; }

  void build(int k, int s, int e) {
    if (s + 1 == e) {
      st[k] = 1;
      return;
    }
    int m = (s + e) >> 1;
    build(lp);
    build(rp);
    st[k] = merge(st[ls], st[rs]);
  }

  void upd(int k, int s, int e, int i, int v) {
    if (s + 1 == e) {
      st[k] = v;
      return;
    }
    int m = (s + e) >> 1;
    if (i < m) {
      upd(lp, i, v);
    } else {
      upd(rp, i, v);
    }
    st[k] = merge(st[ls], st[rs]);
  }

  int kth(int k, int s, int e, int v) {
    if (s + 1 == e) return s;
    int m = (s + e) >> 1;
    if (st[rs] > v)
      return kth(rp, v);
    else
      return kth(lp, v - st[rs]);
  }

  void upd(int i, int v) { upd(0, 0, n, i, v); }
  int kth(int v) { return kth(0, 0, n, v); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  STree st(n);
  vi a(n);
  FOR(i, 0, n) { cin >> a[i]; }
  vi ans;
  ROF(i, n, 0) {
    int pos = st.kth(a[i]);
    ans.pb(pos);
    st.upd(pos, 0);
  }
  reverse(ALL(ans));
  for (auto x : ans) cout << x + 1 << " ";

  return 0;
}