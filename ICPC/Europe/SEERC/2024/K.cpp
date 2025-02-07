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

#define LAZY_NEUT 0
#define VAL_NEUT 0
struct STree {
  ll n;
  vector<ll> st, lazy;
  STree(ll n) : st(4 * n + 5, VAL_NEUT), lazy(4 * n + 5, LAZY_NEUT), n(n) {}
  ll comb(ll x, ll y) { return x + y; }
  void init(ll k, ll s, ll e, vi& a) {
    if (s + 1 == e) {
      st[k] = a[s];
      return;
    }
    ll m = (s + e) / 2;
    init(2 * k + 1, s, m, a);
    init(2 * k + 2, m, e, a);
    st[k] = comb(st[2 * k + 1], st[2 * k + 2]);
  }
  void push(ll k, ll s, ll e) {
    if (lazy[k] == LAZY_NEUT) return;
    st[2 * k + 1] *= 1ll << lazy[k];
    st[2 * k + 2] *= 1ll << lazy[k];
    lazy[2 * k + 1] += lazy[k];
    lazy[2 * k + 2] += lazy[k];
    lazy[k] = LAZY_NEUT;
  }
  ll query(ll k, ll s, ll e, ll a, ll b) {
    if (a <= s && e <= b) return st[k];
    if (e <= a || s >= b) return VAL_NEUT;
    push(k, s, e);
    ll m = (s + e) / 2;
    return comb(query(2 * k + 1, s, m, a, b), query(2 * k + 2, m, e, a, b));
  }
  void updPoint(ll k, ll s, ll e, ll pos, ll v) {
    if (s + 1 == e) {
      st[k] += v;
      return;
    }
    ll m = (s + e) / 2;
    if (pos < m)
      updPoint(2 * k + 1, s, m, pos, v);
    else
      updPoint(2 * k + 2, m, e, pos, v);
    st[k] = comb(st[2 * k + 1], st[2 * k + 2]);
  }

  void updRange(ll k, ll s, ll e, ll a, ll b) {
    if (e <= a || s >= b) return;
    if (a <= s && e <= b) {
      st[k] *= 2ll;
      lazy[k]++;
      return;
    }
    push(k, s, e);
    ll m = (s + e) / 2;
    updRange(2 * k + 1, s, m, a, b);
    updRange(2 * k + 2, m, e, a, b);
    st[k] = comb(st[2 * k + 1], st[2 * k + 2]);
  }

  ll find(ll k, ll s, ll e, ll x) {
    if (s + 1 == e) {
      return s;
    }
    ll m = (s + e) / 2;
    push(k, s, e);
    if (st[2 * k + 1] >= x)
      return find(2 * k + 1, s, m, x);
    else
      return find(k * 2 + 2, m, e, x - st[2 * k + 1]);
  }
  ll query(ll a, ll b) { return query(0, 0, n, a, b); }
  ll find(ll x) { return find(0, 0, n, x); }
  void updPoint(ll pos, ll v) { updPoint(0, 0, n, pos, v); }
  void updRange(ll a, ll b) { updRange(0, 0, n, a, b); }
  void init(vi& a) { init(0, 0, n, a); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vi a(n, 1);
  STree st(n);
  st.init(a);

  while (q--) {
    ll op;
    cin >> op;
    if (op == 1) {
      ll l, r;
      cin >> l >> r;
      ll x = st.find(l);
      ll y = st.find(r);
      if (x == y) {
        st.updPoint(x, r - l + 1);
      } else {
        ll sumaIzq = st.query(0, x + 1) - l + 1;
        ll sumaDer = r - st.query(0, y);
        st.updPoint(x, sumaIzq);
        st.updPoint(y, sumaDer);

        if (x + 1 <= y - 1) {
          st.updRange(x + 1, y);
        }
        // cout << st.query(x + 1, x + 2) << ENDL;
      }

      // FOR(i, 1, n + 10) { cout << s[st.find(i)] << " "; }
      // cout << ENDL;
    } else {
      ll i;
      cin >> i;
      ll x = st.find(i);
      cout << s[x] << ENDL;
    }
  }

  return 0;
}