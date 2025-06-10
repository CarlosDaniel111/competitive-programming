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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, T;
  cin >> n >> T;
  vector<vi> sensors(n, vi(T));
  FOR(i, 0, n) {
    FOR(j, 0, T) { cin >> sensors[i][j]; }
  }

  vector<vi> pref(n, vi(T + 1));
  FOR(i, 0, n) {
    FOR(j, 0, T) { pref[i][j + 1] = pref[i][j] + sensors[i][j]; }
  }

  ll L, U;
  cin >> L >> U;

  if (n == 1) {
    if (L <= T && T <= U) {
      cout << pref[0][T] << ENDL;
    } else {
      cout << -1 << ENDL;
    }
    return 0;
  }
  vector<vector<pi>> best(T + 1, vector<pi>(T + 1, {0, 0}));
  vector<vector<pi>> best2(T + 1, vector<pi>(T + 1, {0, 0}));
  vector<vi> dp(n + 5, vi(T + 5, -1));
  FOR(t, 0, T) {
    if (t + L > T) break;
    FOR(tp, t + L, min(T, t + U) + 1) {
      FOR(i, 0, n) {
        best[t][tp] = max(best[t][tp], {pref[i][tp] - pref[i][t], i});
      }
      FOR(i, 0, n) {
        if (i == best[t][tp].second) continue;
        best2[t][tp] = max(best2[t][tp], {pref[i][tp] - pref[i][t], i});
      }
    }
  }
  auto solve = [&](auto self, ll ant, ll t) -> ll {
    if (t > T) return -1e15;
    if (t == T) return 0;
    ll &ans = dp[ant][t];
    if (ans != -1) return ans;

    ans = -1e15;
    if (t + L > T) return ans;

    FOR(tp, t + L, min(T, t + U) + 1) {
      if (best[t][tp].second == ant)
        ans =
            max(ans, best2[t][tp].first + self(self, best2[t][tp].second, tp));
      else
        ans = max(ans, best[t][tp].first + self(self, best[t][tp].second, tp));
    }

    return ans;
  };
  ll ans = solve(solve, n, 0);
  if (ans <= 0) ans = -1;
  cout << ans << ENDL;

  return 0;
}