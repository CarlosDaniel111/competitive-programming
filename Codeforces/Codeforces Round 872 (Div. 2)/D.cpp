#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

constexpr ll MOD = 1e9 + 7;

constexpr ll LIM = 2e5 + 5;
ll inv[LIM + 1];
ll fact[LIM + 1];
void precalc_inv() {
  inv[1] = 1;
  FOR(i, 2, LIM)
  inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
}

ll invfact[LIM + 1];

void precalc_invfact() {
  precalc_inv();
  invfact[1] = 1;
  for (ll i = 2; i < LIM; i++)
    invfact[i] = invfact[i - 1] * inv[i] % MOD;
}

ll comb(ll n, ll k) {
  if (n < k)
    return 0;
  return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

vector<vi> g;
vi tam;

void dfs(ll u, ll p) {
  tam[u] = 1;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    tam[u] += tam[v];
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  fact[1] = 1;
  FOR(i, 2, LIM) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  precalc_invfact();
  ll n, k;

  cin >> n >> k;
  g.assign(n, vi());
  tam.assign(n, 0);
  FOR(i, 0, n - 1) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  if (k % 2 == 1) {
    cout << 1 << ENDL;
    return 0;
  }
  if (n == 2) {
    cout << 2 << ENDL;
    return 0;
  }
  dfs(0, -1);
  ll ans = n * (n - 1);
  FOR(i, 0, n) {
    ans += (tam[i] - 1) * (n - tam[i]);
  }
  // ans -= n;
  ans = ans * inv[comb(n, 2)] % MOD;
  cout << ans << ENDL;

  return 0;
}