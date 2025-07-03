#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
const int MOD = 998244353, MAX = 1e6 + 5;
ll invfact[MAX];
ll fact[MAX];
ll inv[MAX];
void precalc_inverse(int m = MOD) {
  inv[1] = 1;
  FOR(i, 2, MAX) { inv[i] = m - (m / i) * inv[m % i] % m; }
}
void precalc_invfact() {
  precalc_inverse();
  invfact[1] = fact[1] = fact[0] = invfact[0] = 1;

  for (int i = 2; i < MAX; i++) {
    fact[i] = fact[i - 1] * i % MOD;
    invfact[i] = invfact[i - 1] * inv[i] % MOD;
  }
}
ll comb(int n, int k) {
  if (n < k) return 0;
  return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  precalc_invfact();
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    cout << comb(n + 1, k + 1) << ENDL;
  }

  return 0;
}