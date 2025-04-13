#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

void solve() {
  ll n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n)
  cin >> a[i];
  vector<vi> g(n);
  FOR(i, 1, n) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v), g[v].pb(u);
  }

  vector<vi> dp(n, vi(22, 4e18));
  auto dfs = [&](auto self, ll u, ll p) -> void {
    FOR(i, 0, 22) {
      dp[u][i] = a[u] * (i + 1);
    }
    for (auto v : g[u]) {
      if (v == p) continue;
      self(self, v, u);
      FOR(i, 0, 22) {
        ll mn = 4e18;
        FOR(j, 0, 22) {
          if (i == j) continue;
          mn = min(mn, dp[v][j]);
        }
        dp[u][i] += mn;
      }
    }
  };

  dfs(dfs, 0, -1);

  cout << *min_element(ALL(dp[0])) << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}