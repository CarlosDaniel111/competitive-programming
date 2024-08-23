#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

constexpr ll MOD = 998244353;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;
  map<ll, ll> cnt;
  vi color(n), sz(n, 0);
  FOR(i, 0, n) {
    cin >> color[i];
    cnt[color[i]]++;
  }
  vector<vi> g(n);
  FOR(i, 1, n) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  vector<vi> dp(n, vi(6010));
  ll m, c;

  auto dfs = [&](auto self, ll u, ll p) -> void {
    ll t = color[u] == c ? 1 : -1;
    sz[u] = dp[u][m + t] = 1;
    for (auto v : g[u]) {
      if (v == p) continue;
      self(self, v, u);

      ll m1 = min(sz[u], m), m2 = min(sz[v], m);
      vi tmp(m * 2 + 1);
      FOR(i, 0, m * 2 + 1) tmp[i] = dp[u][i];

      FOR(i, -m1, m1 + 1) {
        for (ll j = -m2; j <= m2 && i + j <= m; j++) {
          if (i + j + m < 0) continue;
          (dp[u][i + j + m] += tmp[i + m] * dp[v][j + m] % MOD) %= MOD;
        }
      }
      sz[u] += sz[v];
    }
  };

  ll ans = 0;
  for (auto [x, y] : cnt) {
    c = x, m = y;
    dfs(dfs, 0, -1);
    FOR(i, 0, n) {
      FOR(j, 1, m + 1)(ans += dp[i][j + m]) %= MOD;
      FOR(j, -m, m + 1) dp[i][j + m] = 0;
    }
  }
  cout << ans << ENDL;

  return 0;
}