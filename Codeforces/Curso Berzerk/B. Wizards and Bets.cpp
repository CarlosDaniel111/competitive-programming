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

ll det(vector<vector<ll>>& a, ll mod) {
  ll n = SZ(a);
  ll ans = 1;
  FOR(i, 0, n) {
    FOR(j, i + 1, n) {
      while (a[j][i] != 0) {  // gcd step
        ll t = a[i][i] / a[j][i];
        if (t) FOR(k, i, n) a[i][k] = (a[i][k] - a[j][k] * t) % mod;
        swap(a[i], a[j]);
        ans *= -1;
      }
    }
    ans = ans * a[i][i] % mod;
    if (!ans) return 0;
  }
  return (ans + mod) % mod;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, m, p;
  cin >> n >> m >> p;
  vi in(n, 0), out(n, 0);
  vector<vi> g(n);
  FOR(i, 0, m) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    in[v]++;
    out[u]++;
  }
  vi st, ed;
  FOR(i, 0, n) {
    if (!in[i]) st.pb(i);
    if (!out[i]) ed.pb(i);
  }

  vi vis(n, 0);
  vector<vi> cnt(n, vi(n, 0));
  auto dfs = [&](auto self, ll u) -> void {
    if (vis[u]) return;
    vis[u] = 1;
    if (!out[u]) {
      cnt[u][u] = 1;
      return;
    }
    for (auto v : g[u]) {
      if (!vis[v]) self(self, v);
      for (auto sink : ed) {
        cnt[u][sink] += cnt[v][sink];
        cnt[u][sink] %= p;
      }
    }
  };

  FOR(i, 0, SZ(st)) {
    if (!vis[st[i]]) dfs(dfs, st[i]);
  }
  vector<vi> mat(SZ(st), vi(SZ(st), 0));
  FOR(i, 0, SZ(st)) {
    FOR(j, 0, SZ(st)) { mat[i][j] = cnt[st[i]][ed[j]] % p; }
  }

  cout << det(mat, p) << ENDL;

  return 0;
}