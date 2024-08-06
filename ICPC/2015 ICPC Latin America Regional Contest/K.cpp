#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

constexpr ll INF = 1e9 + 5;

#define NEUT 10000000000005
#define oper(a, b) min(a, b)
template <class T>
struct SegTree {
  ll n;
  vector<T> A, st;

  inline ll lc(ll p) { return (p << 1) + 1; }
  inline ll rc(ll p) { return (p << 1) + 2; }

  void init(vector<T> v) {
    A = v;
    n = SZ(A);
    st.resize(n * 4);
    build(0, 0, n - 1);
  }

  void build(ll p, ll L, ll R) {
    if (L == R) {
      st[p] = A[L];
      return;
    }
    ll m = (L + R) >> 1;
    build(lc(p), L, m);
    build(rc(p), m + 1, R);
    st[p] = oper(st[lc(p)], st[rc(p)]);
  }

  T query(ll l, ll r, ll p, ll L, ll R) {
    if (l <= L && r >= R) return st[p];
    if (l > R || r < L) return NEUT;
    ll m = (L + R) >> 1;
    return oper(query(l, r, lc(p), L, m), query(l, r, rc(p), m + 1, R));
  }
  T query(ll l, ll r) { return query(l, r, 0, 0, n - 1); }

  void update(ll i, T val, ll p, ll L, ll R) {
    if (L > i || R < i) return;
    if (L == R) {
      st[p] = val;
      return;
    }
    ll m = (L + R) >> 1;
    update(i, val, lc(p), L, m);
    update(i, val, rc(p), m + 1, R);
    st[p] = oper(st[lc(p)], st[rc(p)]);
  }
  void update(ll i, T val) { update(i, val, 0, 0, n - 1); }
};

struct Shop {
  ll l, s, c;
};
bool cmp(Shop s1, Shop s2) {
  return s1.l > s2.l;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, m;
  cin >> n >> m;
  vi a(n);
  FOR(i, 0, n) {
    cin >> a[i];
  }
  vi pref(n + 1, 0);
  FOR(i, 1, n + 1)
  pref[i] = pref[i - 1] + a[i - 1];
  vector<Shop> tiendas(m);
  FOR(i, 0, m) {
    cin >> tiendas[i].l >> tiendas[i].s >> tiendas[i].c;
    tiendas[i].l--;
  }
  sort(ALL(tiendas), cmp);
  SegTree<ll> st;
  bool primera = true;
  st.init(vi(n + 1, INF));
  st.update(n, 0);
  for (Shop tienda : tiendas) {
    ll prox = upper_bound(ALL(pref), pref[tienda.l] + tienda.s) - pref.begin();
    ll curr = min(st.query(tienda.l, prox - 1) + tienda.c, st.query(tienda.l, tienda.l));
    st.update(tienda.l, curr);
  }
  ll ans = st.query(0, 0);
  if (ans >= INF) ans = -1;
  cout << ans << ENDL;

  return 0;
}