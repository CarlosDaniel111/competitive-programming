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

const ll MOD = 998244353, MAX = 5e5 + 5;

ll invfact[MAX], fact[MAX];
ll inv[MAX];
void precalc_inv(ll m = MOD) {
  inv[0] = inv[1] = 1;
  FOR(i, 2, MAX) { inv[i] = m - (m / i) * inv[m % i] % m; }
}
void precalc_invfact() {
  precalc_inv();
  fact[0] = fact[1] = invfact[0] = invfact[1] = 1;
  for (ll i = 2; i < MAX; i++) {
    invfact[i] = invfact[i - 1] * inv[i] % MOD;
    fact[i] = fact[i - 1] * i % MOD;
  }
}

ll comb(ll n, ll k) {
  if (n < k or n < 0 or k < 0) return 0;
  return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

void solve() {
  vi c(26);
  ll tot = 0;
  FOR(i, 0, 26) {
    cin >> c[i];
    tot += c[i];
  }
  vector<vi> dp(26, vi(tot + 5, -1));

  auto solve = [&](auto self, ll i, ll even, ll odd) -> ll {
    if (even < 0 or odd < 0) return 0;
    if (i == 26) return (odd + even) == 0;
    ll& ans = dp[i][even];
    if (ans != -1) return ans;
    if (!c[i]) return ans = self(self, i + 1, even, odd);
    ans = comb(even, c[i]) * self(self, i + 1, even - c[i], odd) % MOD;
    (ans += comb(odd, c[i]) * self(self, i + 1, even, odd - c[i]) % MOD) %= MOD;
    return ans;
  };
  cout << solve(solve, 0, tot / 2, (tot + 1) / 2) << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  precalc_invfact();

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}