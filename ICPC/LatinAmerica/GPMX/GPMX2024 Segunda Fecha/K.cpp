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

constexpr ll MOD = 1e9 + 7;

ll be(ll a, ll b, ll m = MOD) {
  ll res = 1;
  a %= m;
  while (b) {
    if (b & 1) {
      res = res * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

ll modInverse(ll b) { return be(b, MOD - 2) % MOD; }

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, k, invN;
  cin >> n >> k;
  invN = modInverse(n);

  ll ans = n % MOD * modInverse(k - 1) % MOD;
  ROF(i, k, 0) { ans = (1 + (n - i) % MOD * invN % MOD * ans) % MOD; }
  cout << ans << ENDL;

  return 0;
}