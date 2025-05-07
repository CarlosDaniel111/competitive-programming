#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve() {
  int n, q;
  cin >> n >> q;
  vector<pair<int, char>> queries(q);
  FOR(i, 0, q) {
    cin >> queries[i].first >> queries[i].second;
    queries[i].first--;
  }

  auto getCost = [&](int x, int y) -> int {
    int gap = 0, res = 0;
    FOR(i, 0, q) {
      if (queries[i].first == y && queries[i].second == '-') {
        gap++;
      }
      if (queries[i].first == x && queries[i].second == '+') {
        gap--;
      }
      res = min(gap, res);
    }
    return -res + 1;
  };

  vector<vi> cost(n, vi(n));
  FOR(i, 0, n) {
    FOR(j, 0, n) {
      if (i == j) continue;
      cost[i][j] = getCost(i, j);
    }
  }

  vector<vi> dp(1 << n, vi(n, 5e8));
  FOR(i, 0, n) dp[1 << i][i] = 1;
  FOR(mask, 1, 1 << n) {
    FOR(u, 0, n) {
      if (dp[mask][u] == 5e8) continue;
      FOR(v, 0, n) {
        if ((mask >> v) & 1) continue;
        int sigmask = mask + (1 << v);
        dp[sigmask][v] = min(dp[sigmask][v], dp[mask][u] + cost[u][v]);
      }
    }
  }

  vi inicial(n, 0);
  FOR(i, 0, q) { inicial[queries[i].first] += (queries[i].second == '+'); }

  int ans = 5e8;
  FOR(i, 0, n) { ans = min(ans, dp[(1 << n) - 1][i] + inicial[i]); }
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;

  while (t--) solve();

  return 0;
}