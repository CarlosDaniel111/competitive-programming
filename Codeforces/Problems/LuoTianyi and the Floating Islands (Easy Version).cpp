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

ll be(ll a, ll b, ll m = MOD) {
  ll res = 1;
  a %= m;
  while (b) {
    if (b & 1) {
      res = res * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

ll modInverse(ll b) { return be(b, MOD - 2) % MOD; }
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
  ll ans = n * (n - 1) / 2;
  FOR(i, 0, n) {
    ans += (tam[i]) * (n - tam[i]) % MOD;
    ans %= MOD;
  }
  ll den = n * (n - 1) / 2;
  ans = ans * modInverse(den) % MOD;
  cout << ans << ENDL;

  return 0;
}
