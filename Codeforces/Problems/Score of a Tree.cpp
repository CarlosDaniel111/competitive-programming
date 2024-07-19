#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
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

void solve() {
  int n;
  cin >> n;
  vector<vi> g(n);
  FOR(i, 1, n) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  ll suma = 0;

  auto dfs = [&](auto self, int u, int p) -> int {
    int mxh = 0;
    for (auto v : g[u]) {
      if (v == p) continue;
      mxh = max(self(self, v, u), mxh);
    }
    mxh++;
    suma += mxh;
    return mxh;
  };
  dfs(dfs, 0, -1);
  suma %= MOD;
  ll ans = suma * be(2, n - 1) % MOD;
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}