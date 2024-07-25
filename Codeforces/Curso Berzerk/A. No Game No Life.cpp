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
constexpr ll EPS = 0;

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

ll gaussMod(vector<vi> &a, vi &ans) {
  ll n = SZ(a), m = SZ(a[0]) - 1;
  vi where(m, -1);
  for (ll col = 0, row = 0; col < m && row < n; ++col) {
    ll sel = row;
    FOR(i, row, n)
    if (abs(a[i][col]) > abs(a[sel][col])) sel = i;
    if (abs(a[sel][col]) <= EPS) continue;

    FOR(i, col, m + 1)
    swap(a[sel][i], a[row][i]);
    where[col] = row;

    FOR(i, 0, n) {
      if (i != row) {
        ll c = 1LL * a[i][col] * modInverse(a[row][col]) % MOD;
        for (ll j = col; j <= m; ++j) a[i][j] = (MOD + a[i][j] - (1LL * a[row][j] * c) % MOD) % MOD;
      }
    }
    ++row;
  }

  ans.assign(m, 0);
  FOR(i, 0, m) {
    if (where[i] != -1) ans[i] = 1LL * a[where[i]][m] * modInverse(a[where[i]][i]) % MOD;
  }
  FOR(i, 0, n) {
    ll sum = 0;
    FOR(j, 0, m)
    sum = (sum + 1LL * ans[j] * a[i][j]) % MOD;
    if (abs(sum - a[i][m]) > EPS) return 0;
  }

  FOR(i, 0, m)
  if (where[i] == -1) return 1e9;  /// infinitas soluciones
  return 1;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, m;
  cin >> n >> m;
  vector<vi> g(n);
  FOR(i, 0, m) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
  }

  vi vis(n, 0);
  vi grundy(n, 0);
  vi cnt(525, 0);
  auto dfs = [&](auto self, ll u) -> void {
    vis[u] = true;
    vi t(525, 0);
    for (auto v : g[u]) {
      if (!vis[v]) self(self, v);
      t[grundy[v]] = 1;
    }
    // Encontrar MEX
    for (ll i = 0;; i++) {
      if (!t[i]) {
        grundy[u] = i;
        break;
      }
    }
    cnt[grundy[u]]++;
  };

  FOR(i, 0, n) {
    if (!vis[i]) dfs(dfs, i);
  }

  vector<vi> sistema(512, vi(513, 0));
  ll den = modInverse(n + 1);
  FOR(i, 0, 512) {
    FOR(j, 0, 512) {
      sistema[i][j] = (cnt[i xor j] * den) % MOD;
    }
    sistema[i][i] = (sistema[i][i] - 1 + MOD) % MOD;
    if (i) {
      sistema[i][512] = MOD - den;
    }
  }
  vi ans;
  gaussMod(sistema, ans);
  cout << (ans[0]) % MOD << ENDL;

  return 0;
}