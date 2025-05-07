#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

constexpr ll MAX = 5e3 + 15;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  sort(ALL(a));
  vi frec(MAX, 0);
  FOR(i, 0, n) {
    FOR(j, i + 1, n) { frec[a[j] - a[i]]++; }
  }
  vi suffixSum(MAX, 0);  //[l,MAX)
  ROF(i, MAX - 1, 0) { suffixSum[i] = suffixSum[i + 1] + frec[i]; }

  ll num = 0;
  FOR(i, 0, MAX) {
    FOR(j, 0, MAX - i - 1) { num += frec[i] * frec[j] * suffixSum[i + j + 1]; }
  }

  double den = n * (n - 1) / 2;
  den = den * den * den;
  cout << setprecision(9) << fixed;
  double ans = num / den;
  cout << ans << ENDL;

  return 0;
}