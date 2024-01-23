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

const ll EPS = 0, MOD = 13, INF = 1e8;

ll modpow(ll a, ll b) {
  ll res = 1;
  a %= MOD;
  while (b) {
    if (b & 1)
      res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}

ll modInverse(ll b) { return modpow(b, MOD - 2) % MOD; }

ll gauss(vector<vi> &a, vi &ans) {
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
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n, s, t, m, cnt = 0;
  cin >> n >> s >> t >> m;
  s--, t--;
  map<pi, ll> mapa;
  vector<vi> input(m);
  vi time(m), locations(m);
  FOR(i, 0, m) {
    cin >> time[i] >> locations[i];
    input[i].resize(locations[i]);
    FOR(j, 0, locations[i]) {
      cin >> input[i][j];
      input[i][j]--;
      if (j == 0) continue;
      ll u = input[i][j], v = input[i][j - 1];
      if (u > v) swap(u, v);
      if (!mapa.count({u, v})) mapa[{u, v}] = cnt++;
    }
  }

  vector<vi> matriz(m, vi(cnt + 1, 0));
  FOR(i, 0, m) {
    FOR(j, 1, locations[i]) {
      ll u = input[i][j], v = input[i][j - 1];
      if (u > v) swap(u, v);
      matriz[i][mapa[{u, v}]]++;
      matriz[i][mapa[{u, v}]] %= MOD;
    }
    matriz[i][cnt] = time[i];
  }

  vi res;
  gauss(matriz, res);
  vector<vi> g(n, vi(n, INF));
  FOR(i, 0, n) {
    FOR(j, 0, n) {
      if (mapa.count({i, j})) {
        g[i][j] = g[j][i] = res[mapa[{i, j}]];
      }
    }
    g[i][i] = 0;
  }

  FOR(k, 0, n) {
    FOR(i, 0, n) {
      FOR(j, 0, n) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }

  cout << g[s][t] << ENDL;

  return 0;
}