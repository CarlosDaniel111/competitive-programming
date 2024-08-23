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
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<vi> g(n + 5, vi(n + 5, 0));
  FOR(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u][v] = 1;
    g[v][u] = 1;
  }

  vi dp(n + 1, 0);
  FOR(u, 0, n + 1) {
    // Nodo solo
    FOR(v, 0, u) {
      dp[u] = 1;
      if (!g[u][v]) {
        dp[u] = 0;
        break;
      }
    }

    // Uniendote al conjunto que pertenece v
    FOR(v, 0, u) {
      bool puede = 1;
      if (g[u][v]) continue;
      FOR(k, v + 1, u) {
        if (g[u][k] || g[v][k]) continue;
        puede = 0;
        break;
      }

      if (puede) dp[u] += dp[v];
    }
  }

  cout << dp[n] << ENDL;

  return 0;
}