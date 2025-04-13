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

  ll n;
  vector<pi> st;
  vi lazy;

  STree(ll n) : n(n), st((n << 2) + 5), lazy((n << 2) + 5) {}

  pi merge(pi x, pi y) {
    return {min(x.first, y.first), max(x.second, y.second)};
  }

  void pull(ll k) { st[k] = merge(st[ls], st[rs]); }

  void apply(ll k, ll s, ll e, ll v) {
    st[k].first += v;
    st[k].second += v;
    lazy[k] += v;
  }

  void push(ll k, ll s, ll e) {
    if (lazy[k]) {
      ll m = (s + e) >> 1;
      apply(lp, lazy[k]);
      apply(rp, lazy[k]);
      lazy[k] = 0;
    }
  }

  pi query(ll k, ll s, ll e, ll a, ll b) {
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

  void upd(ll k, ll s, ll e, ll a, ll b, ll v) {
    if (a <= s && e <= b) {
      apply(k, s, e, v);
      return;
    }
    push(k, s, e);
    ll m = (s + e) >> 1;
    if (a < m) {
      upd(lp, a, b, v);
    }
    if (b > m) {
      upd(rp, a, b, v);
    }
    pull(k);
  }

  pi query(ll a, ll b) { return query(0, 0, n, a, b); }
  void upd(ll a, ll b, ll v) { upd(0, 0, n, a, b, v); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;
  vector<tuple<char, ll, ll>> input(n);
  vi nums;
  FOR(i, 0, n) {
    char c;
    ll len, col;
    cin >> c >> len >> col;
    input[i] = {c, len, col};
    if (c == '-') {
      nums.pb(col);
      nums.pb(col + len);
    } else {
      nums.pb(col);
      nums.pb(col + 1);
    }
  }
  sort(ALL(nums));
  nums.erase(unique(ALL(nums)), nums.end());
  auto get = [&](ll x) -> ll {
    return lower_bound(ALL(nums), x) - nums.begin();
  };

  STree st(SZ(nums) + 5);

  FOR(i, 0, n) {
    auto [c, len, col] = input[i];
    if (c == '-') {
      ll l = get(col), r = get(col + len);
      auto [mn, mx] = st.query(l, r);
      if (mn == mx) {
        cout << 'S';
        st.upd(l, r, 1);
      } else {
        cout << 'U';
      }
    } else {
      cout << 'S';
      ll l = get(col), r = get(col + 1);
      st.upd(l, r, len);
    }
  }

  return 0;
}