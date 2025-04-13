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

struct STree {
#define ls (k << 1) + 1
#define rs (k << 1) + 2
#define lp ls, s, m
#define rp rs, m, e

  ll n;
  vector<ll> st;

  STree(ll n) : n(n), st((n << 2) + 5) {}

  ll merge(ll x, ll y) { return x + y; }

  void pull(ll k) { st[k] = merge(st[ls], st[rs]); }

  void build(ll k, ll s, ll e, vector<ll>& a) {
    if (s + 1 == e) {
      st[k] = a[s];
      return;
    }
    ll m = (s + e) >> 1;
    build(lp, a);
    build(rp, a);
    pull(k);
  }

  ll query(ll k, ll s, ll e, ll a, ll b) {
    if (a <= s && e <= b) {
      return st[k];
    }
    ll m = (s + e) >> 1;
    if (a >= m) {
      return query(rp, a, b);
    }
    if (b <= m) {
      return query(lp, a, b);
    }
    return merge(query(lp, a, b), query(rp, a, b));
  }

  void upd(ll k, ll s, ll e, ll i, ll v) {
    if (s + 1 == e) {
      st[k] += v;
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

  ll query(ll a, ll b) { return query(0, 0, n, a, b); }
  void upd(ll i, ll v) { upd(0, 0, n, i, v); }
  void build(vector<ll>& a) { build(0, 0, n, a); }
};

void solve() {
  ll n;
  cin >> n;
  vector<vi> g(n);
  vi w(n);
  set<ll> st;
  vector<vi> pos(n + 1);
  FOR(i, 0, n) {
    cin >> w[i];
    st.insert(w[i]);
    pos[w[i]].pb(i);
  }
  FOR(i, 1, n) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  ll cnt2 = 0;
  vector<pi> euler(n);
  auto dfs2 = [&](auto self, ll u, ll p) -> void {
    euler[u].first = cnt2++;
    for (auto v : g[u]) {
      if (v == p) continue;
      self(self, v, u);
    }
    euler[u].second = cnt2++;
  };

  dfs2(dfs2, 0, -1);

  STree seg(cnt2);
  vi aux(cnt2, 0);
  seg.build(aux);

  vector<ll> cnt(n);
  auto dfs = [&](auto self, ll u, ll p) -> void {
    for (auto v : g[u]) {
      if (v == p) continue;
      self(self, v, u);
      if (w[v] > w[u]) cnt[u]++;
      cnt[u] += cnt[v];
    }
  };

  dfs(dfs, 0, -1);
  ll u = *st.rbegin();
  for (auto v : pos[u]) {
    seg.upd(euler[v].first, 1);
  }
  ll llevamos = SZ(pos[u]);
  st.erase(u);

  while (SZ(st)) {
    ll val = *st.rbegin();
    for (auto u : pos[val]) {
      ll curr = seg.query(euler[u].first, euler[u].second + 1);
      if (curr < llevamos) {
        cout << u + 1 << ENDL;
        return;
      }
    }

    for (auto v : pos[val]) {
      seg.upd(euler[v].first, 1);
    }
    llevamos += SZ(pos[val]);
    st.erase(val);
  }

  cout << 0 << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}