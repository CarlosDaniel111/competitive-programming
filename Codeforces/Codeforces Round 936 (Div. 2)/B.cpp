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

ll modpow(ll a, ll b) {
  ll res = 1;
  a %= MOD;
  while (b) {
    if (b & 1)
      res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res % MOD;
}

void solve() {
  ll n, k;
  cin >> n >> k;
  ll total = 0;
  vi a(n);
  FOR(i, 0, n) {
    cin >> a[i];
    total += (a[i]);
  }
  ll mx1 = -3e15, mx2 = 0;
  FOR(i, 0, n) {
    mx2 = mx2 + a[i];
    if (mx1 < mx2)
      mx1 = mx2;
    if (mx2 < 0)
      mx2 = 0;
  }

  mx1 = max(mx1, 0LL);
  // mx1 %= MOD;
  ll resto = total - mx1;
  // total = (total + MOD) % MOD;
  /*while (resto < MOD) {
    resto += MOD;
  }
  resto %= MOD;
  while (total < MOD) {
    total += MOD;
  }
  total %= MOD;*/
  mx1 %= MOD;
  ll aux = modpow(2, k);
  aux %= MOD;
  ll ans = (aux * mx1) % MOD;
  ans += resto;
  while (ans < MOD) {
    ans += MOD;
  }
  ans %= MOD;

  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}