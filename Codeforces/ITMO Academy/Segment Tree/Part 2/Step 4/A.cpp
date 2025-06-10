#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

struct STree {
#define ls (k << 1) + 1
#define rs (k << 1) + 2
#define lp ls, s, m
#define rp rs, m, e

  int n;
  vector<ll> st, lazyAdd, lazyEq;

  STree(int n)
      : n(n),
        st((n << 2) + 5, 0),
        lazyAdd((n << 2) + 5, 0),
        lazyEq((n << 2) + 5, -1) {}

  ll merge(ll x, ll y) { return (x + y); }

  void applyAdd(int k, int s, int e, ll v) {
    st[k] += (e - s) * v;
    lazyAdd[k] += v;
  }
  void applyEq(int k, int s, int e, ll v) {
    st[k] = (e - s) * v;
    lazyEq[k] = v;
    lazyAdd[k] = 0;
  }

  void push(int k, int s, int e) {
    int m = (s + e) >> 1;
    if (lazyEq[k] != -1) {
      applyEq(lp, lazyEq[k]);
      applyEq(rp, lazyEq[k]);
      lazyEq[k] = -1;
    }
    applyAdd(lp, lazyAdd[k]);
    applyAdd(rp, lazyAdd[k]);
    lazyAdd[k] = 0;
  }

  ll query(int k, int s, int e, int a, int b) {
    if (b <= s or e <= a) return 0;
    if (a <= s && e <= b) return st[k];
    push(k, s, e);
    int m = (s + e) >> 1;
    return merge(query(lp, a, b), query(rp, a, b));
  }

  void add(int k, int s, int e, int a, int b, ll v) {
    if (b <= s or e <= a) return;
    if (a <= s && e <= b) {
      applyAdd(k, s, e, v);
      return;
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    add(lp, a, b, v);
    add(rp, a, b, v);
    st[k] = merge(st[ls], st[rs]);
  }

  void assign(int k, int s, int e, int a, int b, ll v) {
    if (b <= s or e <= a) return;
    if (a <= s && e <= b) {
      applyEq(k, s, e, v);
      return;
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    assign(lp, a, b, v);
    assign(rp, a, b, v);
    st[k] = merge(st[ls], st[rs]);
  }

  ll query(int a, int b) { return query(0, 0, n, a, b); }
  void add(int a, int b, ll v) { add(0, 0, n, a, b, v); }
  void assign(int a, int b, ll v) { assign(0, 0, n, a, b, v); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, q;
  cin >> n >> q;
  STree st(n);
  while (q--) {
    ll op, l, r;
    cin >> op >> l >> r;
    if (op == 1) {
      ll v;
      cin >> v;
      st.assign(l, r, v);
    } else if (op == 2) {
      ll v;
      cin >> v;
      st.add(l, r, v);
    } else {
      cout << st.query(l, r) << ENDL;
    }
  }

  return 0;
}