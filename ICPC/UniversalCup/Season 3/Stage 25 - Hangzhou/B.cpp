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
  ll g, f;
};

const ll BIT1 = (1ull << 63) - 1;

struct STree {
#define ls (k << 1) + 1
#define rs (k << 1) + 2
#define lp ls, s, m
#define rp rs, m, e

  ll n;
  vector<Node> st;
  vi lazy;

  STree(ll n) : n(n), st((n << 2) + 5), lazy((n << 2) + 5, BIT1) {}

  Node merge(Node x, Node y) { return {x.g & y.g, (x.g & y.f) | (y.g & x.f)}; }

  void pull(ll k) { st[k] = merge(st[ls], st[rs]); }

  void apply(ll k, ll s, ll e, ll v) {
    st[k].g &= v;
    if (s + 1 == e)
      st[k].f = st[k].g ^ BIT1;
    else
      st[k].f &= v;
    lazy[k] &= v;
  }

  void push(ll k, ll s, ll e) {
    if (lazy[k] != BIT1) {
      ll m = (s + e) >> 1;
      apply(lp, lazy[k]);
      apply(rp, lazy[k]);
      lazy[k] = BIT1;
    }
  }

  void build(ll k, ll s, ll e, vector<ll>& a) {
    if (s + 1 == e) {
      st[k] = {a[s], a[s] ^ BIT1};
      return;
    }
    ll m = (s + e) >> 1;
    build(lp, a);
    build(rp, a);
    pull(k);
  }

  Node query(ll k, ll s, ll e, ll a, ll b) {
    if (a <= s && e <= b) {
      return st[k];
    }
    push(k, s, e);
    ll m = (s + e) >> 1;
    if (a >= m) {
      return query(rp, a, b);
    }
    if (b <= m) {
      return query(lp, a, b);
    }
    return merge(query(lp, a, b), query(rp, a, b));
  }

  ll getNum(ll k, ll s, ll e, ll a, ll b, ll bit) {
    if (a <= s && e <= b && !((st[k].f >> bit) & 1ll)) {
      return -1;
    }
    if (s + 1 == e) return st[k].g;
    push(k, s, e);
    ll m = (s + e) >> 1;
    if (a >= m) {
      return getNum(rp, a, b, bit);
    }
    if (b <= m) {
      return getNum(lp, a, b, bit);
    }
    ll res = getNum(lp, a, b, bit);
    if (res != -1)
      return res;
    else
      return getNum(rp, a, b, bit);
  }

  void updPoint(ll k, ll s, ll e, ll i, ll v) {
    if (s + 1 == e) {
      st[k] = {v, v ^ BIT1};
      return;
    }
    push(k, s, e);
    ll m = (s + e) >> 1;
    if (i < m) {
      updPoint(lp, i, v);
    } else {
      updPoint(rp, i, v);
    }
    pull(k);
  }

  void updRange(ll k, ll s, ll e, ll a, ll b, ll v) {
    if (a <= s && e <= b) {
      apply(k, s, e, v);
      return;
    }
    push(k, s, e);
    ll m = (s + e) >> 1;
    if (a < m) {
      updRange(lp, a, b, v);
    }
    if (b > m) {
      updRange(rp, a, b, v);
    }
    pull(k);
  }

  Node query(ll a, ll b) { return query(0, 0, n, a, b); }
  void updPoint(ll i, ll v) { updPoint(0, 0, n, i, v); }
  void updRange(ll a, ll b, ll v) { updRange(0, 0, n, a, b, v); }
  ll getNum(ll a, ll b, ll bit) { return getNum(0, 0, n, a, b, bit); }
  void build(vector<ll>& a) { build(0, 0, n, a); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  ll n, q;
  cin >> n >> q;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  STree st(n);
  st.build(a);
  while (q--) {
    ll op;
    cin >> op;
    if (op == 1) {
      ll l, r, v;
      cin >> l >> r >> v;
      l--;
      st.updRange(l, r, v);
    } else if (op == 2) {
      ll i, v;
      cin >> i >> v;
      i--;
      st.updPoint(i, v);
    } else {
      ll l, r;
      cin >> l >> r;
      l--;
      Node curr = st.query(l, r);
      ll ans = -1;
      ROF(k, 63, 0) {
        if ((curr.f >> k) & 1) {
          ll num = st.getNum(l, r, k);
          ans = curr.g;
          ROF(kk, k + 1, 0) {
            if (!((num >> kk) & 1ll) && ((curr.f >> kk) & 1ll)) {
              ans |= 1ll << kk;
            }
          }
          break;
        }
      }
      if (ans == -1) ans = curr.g;
      cout << ans << ENDL;
    }
  }

  return 0;
}