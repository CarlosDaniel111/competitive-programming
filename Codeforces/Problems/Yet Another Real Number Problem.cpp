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
const ll MOD = 1e9 + 7;
ll be(ll a, ll b, ll m = MOD) {
  ll res = 1;
  a %= m;
  while (b) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

void solve() {
  ll n;
  cin >> n;
  ll ans = 0;
  stack<pair<ll, ll>> st;
  FOR(i, 0, n) {
    ll x;
    cin >> x;
    ll d2 = __builtin_ctzll(x);
    x >>= d2;
    while (SZ(st) && (d2 >= 30 or st.top().first <= (x << d2))) {
      ((ans -= st.top().first * (be(2, st.top().second) - 1) % MOD) += MOD) %=
          MOD;
      d2 += st.top().second;
      st.pop();
    }
    (ans += (x * be(2, d2)) % MOD) %= MOD;
    if (d2) st.push({x, d2});
    cout << ans << " ";
  }
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}