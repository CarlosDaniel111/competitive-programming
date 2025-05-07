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
  ll r, g;
  cin >> r >> g;
  if (r > g) swap(r, g);
  ll h = 0;
  FOR(i, 0, 1000) {
    if (i * (i + 1) / 2 == r + g) {
      h = i;
      break;
    }
    if (i * (i + 1) / 2 > r + g) {
      h = i - 1;
      break;
    }
  }

  ll ans = 0;
  vi dp(r + 1, 0);
  dp[0] = 1;
  FOR(i, 1, h + 1) ROF(j, r + 1, i)(dp[j] += dp[j - i]) %= MOD;

  int l = max(0ll, (h * (h + 1) / 2) - g);
  FOR(i, l, r + 1) { (ans += dp[i]) %= MOD; }
  cout << ans << ENDL;

  return 0;
}