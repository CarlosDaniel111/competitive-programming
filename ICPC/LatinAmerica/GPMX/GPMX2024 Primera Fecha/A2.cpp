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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n) { cin >> a[i]; }
  vector<vi> dp(n + 5, vi(n + 5, 3e8));
  FOR(i, 1, n + 1) {
    for (int j = 1; j + i <= n; j++) {
      dp[j][i + j] = min(
          {dp[j][i + j - 1], dp[j + 1][i + j], abs(a[j - 1] - a[i + j - 1])});
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << dp[l][r] << ENDL;
  }

  return 0;
}