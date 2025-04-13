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

ll dp[11][11];
ll n;

ll solve(ll pos, ll ant) {
  if (pos == n) return 1;
  ll &ans = dp[pos][ant];
  if (ans != -1) return ans;
  ans = 0;
  FOR(msk, 0, (1 << n)) {
    ll negros = 0;
    FOR(i, 0, n) {
      if ((msk >> i) & 1) negros++;
    }
    if (pos == 0) {
      ans += solve(pos + 1, negros);
    } else {
      if (negros + ant <= n * 2 - (negros + ant)) ans += solve(pos + 1, negros);
    }
  }
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  memset(dp, -1, sizeof(dp));
  cin >> n;
  cout << solve(0, 0) << ENDL;

  return 0;
}