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

const ll MOD = 998244353;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, k;
  cin >> n >> m >> k;
  vector<vi> g(n);
  FOR(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  queue<int> q;
  q.push(0);
  vi dist(n, -1);
  dist[0] = 0;
  while (SZ(q)) {
    int u = q.front();
    q.pop();
    for (auto v : g[u])
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
  }
  if (dist[1] == -1) {
    cout << 0 << ENDL;
    return 0;
  }
  vi mnDays(n, -1);
  FOR(i, 0, n) if (dist[i] != -1) mnDays[i] = (dist[i] + k - 1) / k;

  vi dp(n, 0);
  dp[0] = 1;
  int D = mnDays[1];

  FOR(d, 1, D + 1) {
    vi ways(n, 0);
    FOR(i, 0, n) if (mnDays[i] == d - 1) ways[i] = dp[i];
    vi nextDp(n, 0);
    FOR(j, 0, k) {
      vi nextWays(n, 0);
      FOR(u, 0, n) {
        if (ways[u] == 0) continue;
        for (int v : g[u]) nextWays[v] = (nextWays[v] + ways[u]) % MOD;
      }
      swap(ways, nextWays);
      FOR(i, 0, n) if (mnDays[i] == d) nextDp[i] = (nextDp[i] + ways[i]) % MOD;
    }
    swap(dp, nextDp);
  }
  cout << dp[1] << ENDL;

  return 0;
}