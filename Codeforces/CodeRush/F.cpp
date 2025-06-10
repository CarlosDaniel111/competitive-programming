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

constexpr int MOD = 1e9 + 7;

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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, idx;
  cin >> n >> idx;
  vi a(n);
  FOR(i, 0, n) { cin >> a[i]; }
  ll num = be(2, a[idx - 1]);
  ll den = 0;
  FOR(i, 0, n) { (den += be(2, a[i])) %= MOD; }
  den = be(den, MOD - 2);
  cout << num * den % MOD << ENDL;

  return 0;
}