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

constexpr ll MOD = 1e9 + 7;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, m;
  cin >> n >> m;
  n += 2;
  vi a(n, 0);
  FOR(i, 0, m) {
    ll x;
    cin >> x;
    a[x]++;
  }
  vi pref(n + 1);
  FOR(i, 0, n) { pref[i + 1] = pref[i] + a[i]; }
  vi dp(n, 0), val(n + m + 1);
  dp[0] = 1;
  FOR(i, 0, n) {
    if (i != 0 && a[i] == 0) {
      dp[i] = val[pref[i] - i + n];
    }
    val[pref[i + 1] - (i + 1) + n] += dp[i];
    val[pref[i + 1] - (i + 1) + n] %= MOD;
  }
  cout << dp[n - 1] << ENDL;

  return 0;
}