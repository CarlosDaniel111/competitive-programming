#include <bits/stdc++.h>
using namespace std;

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
  ll mx, mn, best;
  Node() {}
  Node(ll x, ll l) {
    mx = x - l;
    mn = l - x;
    best = 0;
  }
};

struct STree {
#define ls (k << 1) + 1
#define rs (k << 1) + 2
#define lp ls, s, m
#define rp rs, m, e

  ll n;
  vector<Node> st;

  STree(ll n) : n(n), st((n << 2) + 5) {}

  Node merge(Node x, Node y) {
    Node curr;
    curr.mx = max(x.mx, y.mx);
    curr.mn = max(x.mn, y.mn);
    curr.best = max({y.mx + x.mn, x.best, y.best});
    return curr;
  }

  void pull(ll k) { st[k] = merge(st[ls], st[rs]); }

  void build(ll k, ll s, ll e, vector<ll>& a) {
    if (s + 1 == e) {
      st[k] = {a[s], s};
      return;
    }
    ll m = (s + e) >> 1;
    build(lp, a);
    build(rp, a);
    pull(k);
  }

  void upd(ll k, ll s, ll e, ll i, ll v) {
    if (s + 1 == e) {
      st[k] = {v, s};
      return;
    }
    ll m = (s + e) >> 1;
    if (i < m) {
      upd(lp, i, v);
    } else {
      upd(rp, i, v);
    }
    pull(k);
  }

  ll query() { return st[0].best; }
  void upd(ll i, ll v) { upd(0, 0, n, i, v); }
  void build(vector<ll>& a) { build(0, 0, n, a); }
};

void solve() {
  ll n, q;
  cin >> n >> q;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  vi b = a;
  reverse(ALL(b));
  STree st(n), strev(n);
  st.build(a), strev.build(b);
  cout << max(st.query(), strev.query()) << ENDL;
  while (q--) {
    ll i, x;
    cin >> i >> x;
    i--;
    st.upd(i, x);
    strev.upd(n - i - 1, x);
    cout << max(st.query(), strev.query()) << ENDL;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}