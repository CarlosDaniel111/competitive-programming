#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ll((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define ROF(i, a, b) for (ll i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr ll MOD = 1e9 + 7;
constexpr ll MAXN = 1e5 + 5;
constexpr ll INF = 1e9;
constexpr ll LLINF = 1e18;

set<ll> factors;
vi a;

void primeFactors(ll n) {
  while (n % 2 == 0) {
    factors.insert(2);
    n = n / 2;
  }

  for (ll i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      factors.insert(i);
      n = n / i;
    }
  }
  if (n > 2) factors.insert(n);
}

ll sieve_size;
vi primes;
void sieve(ll n) {
  vector<bool> is_prime(n + 1, 1);

  is_prime[0] = is_prime[1] = 0;
  for (ll p = 2; p <= n; p++) {
    if (is_prime[p]) {
      for (ll i = p * p; i <= n; i += p) is_prime[i] = 0;
      primes.push_back(p);
    }
  }
}

bool probar(ll n, ll x, ll m) {
  FOR(i, 0, x) {
    ll j = i + x;
    while (j < n) {
      if (a[i] % m != a[j] % m) return false;
      j += x;
    }
  }
  return true;
}

void solve() {
  factors.clear();
  ll n;
  cin >> n;
  if (n == 1) {
    cout << 1 << ENDL;
    return;
  }
  primeFactors(n);
  a.clear();
  a.resize(n);
  ll mx = 0;
  FOR(i, 0, n) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  unordered_set<ll> usados;

  ll res = 0;
  FOR(x, 1, n + 1) {
    if (n % x == 0) {
      if (probar(n, n / x, 3e5 + 5)) {
        res++;
      }
    }
  }

  for (auto y : primes) {
    usados.clear();
    if (y > mx) {
      break;
    }
    ll ans = 0;
    FOR(x, 1, n + 1) {
      if (n % x == 0) {
        if (probar(n, n / x, y)) {
          ans++;
        }
      }
    }
    res = max(ans, res);
  }
  cout << res << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  sieve(2e5 + 5);
  cin >> t;
  while (t--)
    solve();

  return 0;
}