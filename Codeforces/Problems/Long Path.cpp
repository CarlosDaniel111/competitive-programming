#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

constexpr ll MOD = 1e9 + 7;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vi p(n);
  FOR(i, 0, n) {
    cin >> p[i];
    p[i]--;
  }
  vi dp(n, 2);
  FOR(i, 1, n) {
    for (int j = p[i]; j < i; j++) {
      (dp[i] += dp[j]) %= MOD;
    }
  }
  ll ans = 0;
  FOR(i, 0, n) { (ans += dp[i]) %= MOD; }
  cout << ans << ENDL;

  return 0;
}