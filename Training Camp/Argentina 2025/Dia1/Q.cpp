#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'
constexpr ll MAX = 500, MOD = 998244353;
ll inv[MAX];
void precalc_inverse(ll m = MOD) {
  inv[1] = 1;
  FOR(i, 2, MAX) { inv[i] = m - (m / i) * inv[m % i] % m; }
}
ll invfact[MAX];
ll fact[MAX];
void precalc_invfact() {
  precalc_inverse();
  fact[0] = fact[1] = invfact[1] = invfact[0] = 1;
  for (ll i = 2; i < MAX; i++) {
    fact[i] = fact[i - 1] * i % MOD;
    invfact[i] = invfact[i - 1] * inv[i] % MOD;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  precalc_invfact();
  ll n;
  cin >> n;
  vector<pi> a(n);
  FOR(i, 0, n) { cin >> a[i].first >> a[i].second; }
  auto dist = [&](ll i, ll j) -> ll {
    return abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second);
  };
  vi mnDist(n, 1e15);
  FOR(i, 0, n) {
    FOR(j, 0, n) {
      if (i == j) continue;
      mnDist[i] = min(mnDist[i], dist(i, j));
    }
  }
  vector<vi> g(n);
  FOR(i, 0, n) {
    FOR(j, 0, n) {
      if (i == j) continue;
      if (dist(i, j) == mnDist[i]) {
        g[i].pb(j);
      }
    }
  }

  vi vis, taken(n, 0);
  auto dfs = [&](auto self, ll u) -> void {
    vis[u] = 1;
    for (auto v : g[u]) {
      if (!vis[v]) self(self, v);
    }
  };
  auto dfs2 = [&](auto self, ll u) -> void {
    taken[u] = 1;
    for (auto v : g[u]) {
      if (!taken[v]) self(self, v);
    }
  };

  vi color;
  FOR(i, 0, n) {
    if (taken[i]) continue;
    vis.assign(n, 0);
    dfs(dfs, i);
    vi comp;
    FOR(i, 0, n) if (vis[i]) comp.pb(i);
    ll m = SZ(comp);
    bool ok = true;
    FOR(j, 0, m) {
      FOR(k, 0, m) {
        if (j == k) continue;
        if (mnDist[i] != dist(comp[j], comp[k])) {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      color.pb(SZ(comp));
      dfs2(dfs2, i);
    } else {
      color.pb(1);
      taken[i] = 1;
    }
  }

  ll m = SZ(color);
  vector<vi> dp(n + 1, vi(m + 1, 0));
  dp[0][0] = 1;
  FOR(j, 0, m) {
    FOR(i, 0, n) {
      (dp[i + 1][j + 1] += dp[i][j]) %= MOD;
      if (color[j] != 1 && i + color[j] <= n) {
        (dp[i + color[j]][j + 1] += dp[i][j]) %= MOD;
      }
    }
  }
  ll ans = 0;
  FOR(i, 1, n + 1) {
    (ans += dp[i][m] * (fact[n] * invfact[n - i] % MOD) % MOD) %= MOD;
  }
  cout << ans << ENDL;

  return 0;
}