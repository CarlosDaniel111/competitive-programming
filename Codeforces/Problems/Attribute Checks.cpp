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
  vector<vector<vector<int>>> nxt(2 * m + 5, vector<vector<int>>(2));
  int curr0 = 0;
  FOR(i, 0, n) {
    int x;
    cin >> x;
    if (x == 0) {
      sort(ALL(nxt[curr0][0]));
      sort(ALL(nxt[curr0][1]));
      curr0++;
      continue;
    }
    nxt[curr0][(x < 0)].pb(abs(x));
  }
  sort(ALL(nxt[curr0][0]));
  sort(ALL(nxt[curr0][1]));
  vector<vi> dp(m + 2, vi(m + 2, 0));
  ROF(i, m + 1, 0) {
    ROF(j, m + 1, 0) {
      int toma = (upper_bound(ALL(nxt[i + j][0]), i) - nxt[i + j][0].begin()) +
                 (upper_bound(ALL(nxt[i + j][1]), j) - nxt[i + j][1].begin());
      dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]) + toma;
    }
  }
  cout << dp[0][0] << ENDL;

  return 0;
}