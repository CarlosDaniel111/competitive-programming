#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

const ll MOD = 1e9 + 7;

vi sz;
vector<vi> g;
ll suma = 0;
ll n;

void dfs(int u, int p) {
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
}

void dfs2(int u, int p) {
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs2(v, u);
    suma += (2ll * sz[v] * (n - sz[v]) % MOD);
    suma %= MOD;
  }
}

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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n;
  g.assign(n, vi());
  sz.assign(n, 0);
  FOR(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(0, -1);
  dfs2(0, -1);
  ll den = n * (n + 1) % MOD;
  ll ans = suma * modInverse(den) % MOD;
  cout << ans << ENDL;
  return 0;
}