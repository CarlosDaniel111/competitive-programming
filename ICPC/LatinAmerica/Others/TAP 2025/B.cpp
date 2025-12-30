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

const ll MOD = 998244353;

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

ll nck(ll n, ll k) {
  ll ans = 1;
  FOR(i, 0, k) {
    ans = ans * (n - i) % MOD;
    ans = ans * be(i + 1, MOD - 2) % MOD;
  }
  return ans % MOD;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, k;
  cin >> n >> k;
  vi c(n, 0);
  FOR(i, k - 1, n) cin >> c[i];
  ll sum = 0;
  FOR(i, k - 1, n) {
    c[i] -= sum;
    sum -= c[i - (k - 1)];
    sum += c[i];
  }

  FOR(i, 0, k - 1) {
    for (ll j = i; j < n; j += k) c[i] = max(c[i], -c[j]);
  }

  ll sMax = 1e18;
  for (ll i = k - 1; i < n; i += k) sMax = min(sMax, c[i]);
  ll sMin = 0;
  FOR(i, 0, k - 1) sMin += c[i];

  if (sMin > sMax) {
    cout << 0 << ENDL;
    return 0;
  }

  sMax -= sMin;
  cout << nck(sMax + k - 1, k - 1) % MOD << ENDL;

  return 0;
}