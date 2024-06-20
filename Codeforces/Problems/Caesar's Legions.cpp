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

constexpr ll MOD = 1e8;

int k1, k2;
ll dp[105][105][15][2];

ll solve(int n1, int n2, int k, int opc) {
  if (!n1 && !n2) return 1;
  ll &ans = dp[n1][n2][k][opc];
  if (ans != -1) return ans;
  ans = 0;
  if (opc == 0) {
    if (n1 && k + 1 <= k1) {
      ans += solve(n1 - 1, n2, k + 1, opc);
      ans %= MOD;
    }
    if (n2) {
      ans += solve(n1, n2 - 1, 1, !opc);
      ans %= MOD;
    }
  } else {
    if (n2 && k + 1 <= k2) {
      ans += solve(n1, n2 - 1, k + 1, opc);
      ans %= MOD;
    }
    if (n1) {
      ans += solve(n1 - 1, n2, 1, !opc);
      ans %= MOD;
    }
  }
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));

  int n1, n2;
  cin >> n1 >> n2 >> k1 >> k2;
  ll ans = solve(n1 - 1, n2, 1, 0);
  ans += solve(n1, n2 - 1, 1, 1);
  ans %= MOD;
  cout << ans << ENDL;

  return 0;
}