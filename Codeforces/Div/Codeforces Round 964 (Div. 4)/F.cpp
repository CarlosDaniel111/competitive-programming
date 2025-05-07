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

constexpr ll MAX = 2e5 + 5;
constexpr ll MOD = 1e9 + 7;

ll inv[MAX];
ll fact[MAX];
void precalc_inv(ll m = MOD) {
  fact[0] = 1;
  FOR(i, 1, MAX) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  inv[0] = 1;
  inv[1] = 1;
  FOR(i, 2, MAX) {
    inv[i] = m - (m / i) * inv[m % i] % m;
  }
}

ll invfact[MAX];
void precalc_invfact() {
  precalc_inv();
  invfact[0] = 1;
  invfact[1] = 1;
  for (int i = 2; i < MAX; i++) invfact[i] = invfact[i - 1] * inv[i] % MOD;
}

ll comb(int n, int k) {
  if (n < k) return 0;
  return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

void solve() {
  ll n, k;
  cin >> n >> k;
  ll cnt0 = 0, cnt1 = 0;
  FOR(i, 0, n) {
    ll x;
    cin >> x;
    cnt0 += (x == 0);
    cnt1 += (x == 1);
  }
  ll ans = 0;

  FOR(i, 0, cnt0 + 1) {
    ll j = k - i;
    if (j <= cnt1 && j > i) {
      (ans += (comb(cnt0, i) * comb(cnt1, j) % MOD)) %= MOD;
    }
  }
  cout << ans % MOD << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  precalc_invfact();

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}