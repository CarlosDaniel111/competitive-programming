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

constexpr ll MOD = 1e9 + 7;

struct STree {
#define ls (k << 1) + 1
#define rs (k << 1) + 2
#define lp ls, s, m
#define rp rs, m, e

  int n;
  vector<ll> st, lazy;

  STree(int n) : n(n), st((n << 2) + 5, 1), lazy((n << 2) + 5, 1) {}

  ll merge(ll x, ll y) { return (x + y) % MOD; }

  void pull(int k) { st[k] = merge(st[ls], st[rs]); }

  void apply(int k, int s, int e, ll v) {
    st[k] *= v;
    st[k] %= MOD;
    lazy[k] *= v;
    lazy[k] %= MOD;
  }

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

  void push(int k, int s, int e) {
    if (lazy[k] != 1) {
      int m = (s + e) >> 1;
      apply(lp, lazy[k]);
      apply(rp, lazy[k]);
      lazy[k] = 1;
    }
  }

  ll query(int k, int s, int e, int a, int b) {
    if (b <= s or e <= a) return 0;
    if (a <= s && e <= b) return st[k];
    push(k, s, e);
    int m = (s + e) >> 1;
    return merge(query(lp, a, b), query(rp, a, b));
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

  ll query(int a, int b) { return query(0, 0, n, a, b); }
  void upd(int a, int b, int v) { upd(0, 0, n, a, b, v); }
  void build() { build(0, 0, n); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, q;
  cin >> n >> q;
  STree st(n);
  st.build();
  while (q--) {
    ll op;
    cin >> op;
    if (op == 1) {
      ll l, r, v;
      cin >> l >> r >> v;
      st.upd(l, r, v);
    } else {
      ll l, r;
      cin >> l >> r;
      cout << st.query(l, r) % MOD << ENDL;
    }
  }

  return 0;
}