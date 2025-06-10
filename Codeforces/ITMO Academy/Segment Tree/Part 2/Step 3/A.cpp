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

struct Node {
  ll sum, pref, suff, res;

  Node() {}
  Node(ll val) : sum(val) { pref = suff = res = max(0ll, val); }
};

struct STree {
#define ls (k << 1) + 1
#define rs (k << 1) + 2
#define lp ls, s, m
#define rp rs, m, e

  int n;
  vector<Node> st;
  vector<ll> lazy;

  STree(int n) : n(n), st((n << 2) + 5, 0), lazy((n << 2) + 5, 1e9 + 5) {}

  Node merge(Node l, Node r) {
    Node curr;
    curr.sum = l.sum + r.sum;
    curr.pref = max(l.pref, l.sum + r.pref);
    curr.suff = max(r.suff, l.suff + r.sum);
    curr.res = max({l.res, r.res, l.suff + r.pref});
    return curr;
  }

  void apply(int k, int s, int e, ll v) {
    st[k].sum = (e - s) * v;
    st[k].pref = st[k].suff = st[k].res = max(0ll, (e - s) * v);
    lazy[k] = v;
  }

  void push(int k, int s, int e) {
    if (lazy[k] != 1e9 + 5) {
      int m = (s + e) >> 1;
      apply(lp, lazy[k]);
      apply(rp, lazy[k]);
      lazy[k] = 1e9 + 5;
    }
  }

  void upd(int k, int s, int e, int a, int b, ll v) {
    if (b <= s or e <= a) return;
    if (a <= s && e <= b) {
      apply(k, s, e, v);
      return;
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    upd(lp, a, b, v);
    upd(rp, a, b, v);
    st[k] = merge(st[ls], st[rs]);
  }

  ll get() { return st[0].res; }
  void upd(int a, int b, int v) { upd(0, 0, n, a, b, v); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, q;
  cin >> n >> q;
  STree st(n);
  while (q--) {
    ll l, r, v;
    cin >> l >> r >> v;
    st.upd(l, r, v);
    cout << st.get() << ENDL;
  }

  return 0;
}