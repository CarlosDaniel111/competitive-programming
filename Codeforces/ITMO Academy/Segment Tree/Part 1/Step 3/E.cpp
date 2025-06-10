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

  STree(int n) : n(n), st((n << 2) + 5, 0) {}

  ll merge(ll x, ll y) { return x + y; }

  void upd(int k, int s, int e, int i, int v) {
    if (e <= i or s > i) return;
    if (s + 1 == e) {
      st[k] += v;
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
  void upd(int i, int v) { upd(0, 0, n, i, v); }
  ll query(int a, int b) { return query(0, 0, n, a, b); }
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
      st.upd(l, v);
      st.upd(r, -v);
    } else {
      int pos;
      cin >> pos;
      cout << st.query(0, pos + 1) << ENDL;
    }
  }

  return 0;
}