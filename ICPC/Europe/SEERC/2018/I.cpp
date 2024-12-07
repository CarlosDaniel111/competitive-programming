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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, m;
  cin >> n >> m;
  vector<vi> g(n + 5, vi(n + 5, 0));
  FOR(i, 0, m) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    if (u > v) swap(u, v);
    g[u][v] = 1;
  }
  vi nums(n);
  iota(ALL(nums), 0);
  vi perm;
  FOR(i, 0, n) {
    ll cnt = 0;
    FOR(j, i + 1, n) cnt += g[i][j];
    perm.pb(nums[cnt]);
    nums.erase(nums.begin() + cnt);
  }

  vi dp(n, 1);

  // Todos los valores menores i son inversiones (hay arista)
  FOR(i, 0, n) {
    bool ok = true;
    FOR(j, 0, i) {
      if (perm[j] < perm[i]) {
        dp[i] = 0;
        break;
      }
    }
  }

  FOR(i, 0, n) {
    if (dp[i]) {
      FOR(j, i + 1, n) {
        // son independientes
        if (perm[j] > perm[i]) {
          bool ok = true;
          FOR(k, i + 1, j) { ok &= perm[i] > perm[k] || perm[k] > perm[j]; }
          if (ok) dp[j] += dp[i];
        }
      }
    }
  }

  ll ans = 0;
  FOR(i, 0, n) {
    bool ok = true;
    FOR(j, i + 1, n) ok &= perm[i] > perm[j];
    if (ok) ans += dp[i];
  }
  cout << ans << ENDL;

  return 0;
}