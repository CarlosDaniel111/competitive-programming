#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

vi primes;
void sieve(int n) {
  vector<bool> is_prime(n + 1, 1);

  is_prime[0] = is_prime[1] = 0;
  for (ll p = 2; p <= n; p++) {
    if (is_prime[p]) {
      for (ll i = p * p; i <= n; i += p) is_prime[i] = 0;
      primes.push_back(p);
    }
  }
}

vi primeFactors(ll N) {
  vi factors;
  for (int i = 0; i < (int)primes.size() && primes[i] * primes[i] <= N; ++i) {
    if (N % primes[i] == 0) factors.push_back(primes[i]);
    while (N % primes[i] == 0) {
      N /= primes[i];
    }
  }
  if (N != 1) factors.push_back(N);
  return factors;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  sieve(1e5 + 5);
  int n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n)
  cin >> a[i];
  vi dp(1e5 + 5, 0);
  int ans = 1;
  ROF(i, n, 0) {
    vi factors = primeFactors(a[i]);
    int mx = 0;
    for (auto x : factors) {
      mx = max(mx, dp[x] + 1);
    }
    for (auto x : factors) {
      dp[x] = mx;
    }
    ans = max(ans, mx);
  }

  cout << ans << ENDL;

  return 0;
}