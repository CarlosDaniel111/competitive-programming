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

struct XorBasis {
  ll D = 30;
  ll basis[30];
  ll sz = 0;

  void insert(ll k) {
    for (ll i = D - 1; i >= 0; i--) {
      if (!(k >> i & 1ll)) continue;
      if (!basis[i]) {
        basis[i] = k;
        sz++;
        return;
      }
      k ^= basis[i];
    }
  }

  // k-th smallest
  ll get_kth(ll k) {
    ll x = 0;
    ll pref = sz;
    for (ll i = D - 1; i >= 0; i--) {
      if (!basis[i]) continue;
      ll p2 = 1ll << (pref - 1);
      ll mini_leq = 1;
      ll maxi_leq = p2;
      if (!(x >> i & 1)) mini_leq += p2, maxi_leq += p2;
      if (mini_leq <= k && maxi_leq >= k) {
        if (!(x >> i & 1)) k -= p2;
        x ^= basis[i];
      } else if (x >> i & 1)
        k -= p2;
      pref--;
    }
    return x;
  }

  // Checa si se puede formar el valor K
  bool check(ll k) {
    for (ll i = D - 1; i >= 0; i--) {
      if (!(k >> i & 1)) continue;
      if (!basis[i]) {
        return false;
      }
      k ^= basis[i];
    }
    return true;
  }

  void merge(const XorBasis &other) { FOR(i, 0, D) insert(other.basis[i]); }
  void merge(const XorBasis &a, const XorBasis &b) {
    *this = a;
    merge(b);
  }
};

ll n, q;
vi a, ans;
vector<pi> queries;

void solve(ll l, ll r, vi &id) {
  if (!SZ(id)) return;
  if (l == r) {
    for (auto i : id) ans[i] = a[l];
    return;
  }
  ll mid = (l + r) / 2;
  vi idL, idR;
  for (auto i : id) {
    if (queries[i].second <= mid) idL.pb(i);
    if (queries[i].first >= mid + 1) idR.pb(i);
  }
  solve(l, mid, idL);
  solve(mid + 1, r, idR);

  vector<XorBasis> left(mid - l + 1), right(r - mid);
  left[0].insert(a[mid]);
  FOR(i, 1, mid - l + 1) {
    left[i] = left[i - 1];
    left[i].insert(a[mid - i]);
  }
  right[0].insert(a[mid + 1]);
  FOR(i, 1, r - mid) {
    right[i] = right[i - 1];
    right[i].insert(a[mid + 1 + i]);
  }

  for (auto i : id) {
    ll ql = queries[i].first, qr = queries[i].second;
    if (ql <= mid && qr > mid) {
      XorBasis curr;
      curr.merge(left[mid - ql], right[qr - mid - 1]);
      ans[i] = curr.get_kth(1ll << curr.sz);
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  a.resize(n);
  FOR(i, 0, n) cin >> a[i];
  cin >> q;
  queries.resize(q);
  FOR(i, 0, q) {
    cin >> queries[i].first >> queries[i].second;
    queries[i].first--, queries[i].second--;
  }
  vi id(q);
  ans.assign(q, 0);
  iota(ALL(id), 0);
  solve(0, n - 1, id);
  for (auto x : ans) {
    cout << x << ENDL;
  }

  return 0;
}