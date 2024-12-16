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
constexpr ll MOD = 1e9 + 7;
ll n;
vector<vi> g;
vector<vi> c;
unordered_map<ll, ll> upd;

ll solve(ll i, ll j) {
  if (i == j) return 1;
  ll &ans = c[i][j];
  if (ans != -1) return ans;
  ans = 0;
  for (auto v : g[i]) {
    ans += solve(v, j);
    ans %= MOD;
  }
  return ans;
}

vi t, b;

void solveT(ll u) {
  t[u] = b[u];
  for (auto v : g[u]) {
    if (t[v] == -1) solveT(v);
    t[u] += t[v];
    t[u] %= MOD;
  }
}

void recalc() {
  for (auto [v, x] : upd) {
    b[v] = x;
  }
  fill(ALL(t), -1);
  FOR(i, 0, n) {
    if (t[i] == -1) {
      solveT(i);
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;

  b.resize(n);
  FOR(i, 0, n) cin >> b[i];
  ll m;
  cin >> m;
  g.assign(n, vi());
  t.resize(n);
  FOR(i, 0, m) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
  }
  c.assign(n, vi(n, -1));
  FOR(i, 0, n) {
    FOR(j, 0, n) { c[i][j] = solve(i, j); }
  }
  recalc();
  ll K = 125;
  ll e, res = 0;
  cin >> e;
  ll cnt = 1;
  while (e--) {
    if (SZ(upd) == K) {
      recalc();
      upd.clear();
    }
    char car;
    cin >> car;
    if (car == 'U') {
      ll u, x;
      cin >> u >> x;
      u--;
      upd[u] = x;
      continue;
    }

    ll u;
    cin >> u;
    u--;
    ll ans = t[u];
    for (auto [v, x] : upd) {
      ans += ((x - b[v] + MOD) % MOD) * c[u][v];
      ans %= MOD;
    }

    res += ans * cnt++;
    res %= MOD;
  }
  cout << res << ENDL;

  return 0;
}