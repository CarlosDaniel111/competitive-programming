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
  int n, m;
  cin >> n >> m;
  vector<vi> g(n);
  FOR(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
  }

  vi dp(n, 1e9);
  dp[0] = 0;
  FOR(i, 0, n - 1) {
    dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    for (auto v : g[i]) {
      dp[v] = min(dp[v], dp[i] + 1);
    }
  }

  vi cnt(n + 1, 0);
  FOR(i, 0, n) {
    int l = i + 1;
    for (auto v : g[i]) {
      int r = v - 2 - dp[i];
      if (l <= r) {
        cnt[l]++;
        cnt[r + 1]--;
      }
    }
  }

  FOR(i, 0, n - 1) {
    cout << (cnt[i] == 0);
    cnt[i + 1] += cnt[i];
  }
  cout << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}