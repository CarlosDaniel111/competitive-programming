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
constexpr ll MOD = 1e9 + 7;
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
  ll num = 0, sum = 0;
  FOR(i, 0, n) {
    ll x;
    cin >> x;
    (num += x * sum % MOD) %= MOD;
    (sum += x) %= MOD;
  }
  ll den = n * (n - 1) % MOD * (be(2, MOD - 2) % MOD) % MOD;
  ll ans = num * be(den, MOD - 2);
  cout << ans % MOD << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}