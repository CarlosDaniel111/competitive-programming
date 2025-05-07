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

vi parent, depth, heavy, head, sz, tin, tout, val;
vector<vi> g;
ll cur_pos, n;

constexpr ll MOD = 998244353;

struct FT {
  vector<ll> s;
  void init(ll n) { s.resize(n); }
  void update(ll pos, ll dif) {  // a[pos] += dif
    for (; pos < SZ(s); pos |= pos + 1) (s[pos] += dif % MOD) %= MOD;
  }
  ll query(ll pos) {  // sum of values in [0, pos)
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) (res += s[pos - 1] % MOD) %= MOD;
    return res % MOD;
  }
};

FT ft;

void dfs(ll u, ll p) {
  parent[u] = p;
  sz[u] = 1;
  tin[u] = cur_pos++;
  for (ll v : g[u]) {
    if (v == p) continue;
    depth[v] = depth[u] + 1;
    dfs(v, u);
    if (heavy[u] == -1)
      heavy[u] = v;
    else if (sz[v] > sz[heavy[u]]) {
      heavy[u] = v;
    }
    sz[u] += sz[v];
  }
  tout[u] = cur_pos++;
}

void decompose(ll u, ll p, ll h) {
  head[u] = h;
  for (ll v : g[u]) {
    if (p == v) continue;
    if (v == heavy[u])
      decompose(v, u, h);
    else
      decompose(v, u, v);
  }
}

void init() {
  parent = vector<ll>(n);
  depth = vector<ll>(n);
  heavy = vector<ll>(n, -1);
  head = vector<ll>(n);
  tin = vi(n);
  tout = vi(n);
  sz = vi(n, 0);
  cur_pos = 0;

  dfs(0, -1);
  decompose(0, -1, 0);
  ft.init(cur_pos + 1);
}

void add_subtree(ll u, ll x) {
  ft.update(tin[u], x);
  ft.update(tout[u], -x + MOD);
}

void modify(ll u, ll d) {
  add_subtree(u, d * (n - sz[u]) % MOD);
  add_subtree(0, d * sz[u] % MOD);
  if (heavy[u] != -1) {
    add_subtree(heavy[u], (-d * sz[heavy[u]] + MOD) % MOD);
  }
}

ll query(ll u) {
  ll ans = ft.query(tin[u] + 1);
  u = head[u];
  while (u) {
    (ans -= val[parent[u]] * sz[u] % MOD) %= MOD;
    u = head[parent[u]];
  }
  return ans % MOD;
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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll q;
  cin >> n >> q;
  g.resize(n);
  FOR(i, 1, n) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  init();
  ll inv = be(n, MOD - 2);
  val.assign(n, 0);
  while (q--) {
    ll op, v, d;
    cin >> op;
    if (op == 1) {
      cin >> v >> d;
      v--;
      (val[v] += d) %= MOD;
      modify(v, d);
    } else {
      cin >> v;
      v--;
      ll ans = query(v) * inv % MOD;
      (ans += MOD) %= MOD;
      cout << ans << ENDL;
    }
  }

  return 0;
}