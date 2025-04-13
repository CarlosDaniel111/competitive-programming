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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vi a(n);
  FOR(i, 0, n) {
    double _;
    cin >> a[i] >> _;
    a[i]--;
  }
  vi dp(m, 0);
  FOR(i, 0, n) { ROF(j, a[i] + 1, 0) dp[a[i]] = max(dp[a[i]], dp[j] + 1); }
  cout << n - *max_element(ALL(dp)) << ENDL;

  return 0;
}