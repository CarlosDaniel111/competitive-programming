#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

ll a0[55], a1[55];
map<ll, int> dp;
int n, m;

int solve(ll s) {
  if (dp.count(s)) return dp[s];
  int c = __builtin_popcountll(s);
  if (c == 1) return 0;
  int ans = 1e9;
  FOR(i, 0, n) {
    ll b0 = (s & a0[i]), b1 = (s & a1[i]);
    if (b0 && b1) ans = min(ans, solve(b0) + solve(b1) + c);
  }
  if (ans == 1e9) {
    cout << "not possible" << ENDL;
    exit(0);
  }
  return dp[s] = ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

    cin >> n >> m;
  FOR(i, 0, m) {
    int k;
    cin >> k;
    vi vis(20, 0);
    FOR(j, 0, k) {
      int x;
      cin >> x;
      vis[x] = 1;
    }
    FOR(j, 0, n) {
      if (vis[j])
        a1[j] |= (1ll << i);
      else
        a0[j] |= (1ll << i);
    }
  }
  int ans = solve((1ll << m) - 1);
  double ans2 = 1.0 * ans / m;
  cout << setprecision(10) << fixed;
  cout << ans2 << ENDL;

  return 0;
}