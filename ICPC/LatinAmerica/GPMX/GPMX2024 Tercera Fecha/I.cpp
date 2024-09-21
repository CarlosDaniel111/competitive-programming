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

constexpr ll MAX = 1e6 + 5, MOD = 1e9 + 7;
ll primo[MAX];

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

void sieve(ll n = MAX) {
  for (ll i = 2; i < n; i++) {
    if (primo[i] == 0) {
      for (ll j = i; j < n; j += i) {
        if (primo[j] == 0) primo[j] = i;
      }
    }
  }
}

ll cnt[MAX];

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  sieve();
  ll n;
  cin >> n;
  FOR(i, 0, n) {
    ll x;
    cin >> x;
    set<ll> primes;
    while (x > 1) {
      primes.insert(primo[x]);
      x /= primo[x];
    }
    vi pf;
    for (auto pr : primes) pf.pb(pr);
    ll m = SZ(pf);
    FOR(msk, 0, 1 << m) {
      ll curr = 1;
      FOR(i, 0, m) {
        if ((msk >> i) & 1) curr *= pf[i];
      }
      cnt[curr]++;
    }
  }

  ll q;
  cin >> q;
  while (q--) {
    ll x;
    cin >> x;
    set<ll> primes;
    while (x > 1) {
      primes.insert(primo[x]);
      x /= primo[x];
    }
    vi pf;
    for (auto pr : primes) pf.pb(pr);
    ll m = SZ(pf);
    ll malo = 0;
    FOR(msk, 0, 1 << m) {
      ll curr = 1;
      ll cnt2 = 0;
      FOR(i, 0, m) {
        if ((msk >> i) & 1) curr *= pf[i], cnt2++;
      }
      if (cnt2 & 1)
        malo += cnt[curr];
      else
        malo -= cnt[curr];
    }

    cout << be(2, -malo) % MOD << ENDL;
  }

  return 0;
}