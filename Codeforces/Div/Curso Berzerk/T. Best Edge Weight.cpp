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

constexpr ll INF = 3e15;

struct DSU {
  vector<ll> e;
  void init(ll n) { e = vi(n, -1); }
  ll size(ll x) { return -e[get(x)]; }
  ll get(ll x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool join(ll a, ll b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

const ll MAX = 3e5 + 5, LOG_MAX = 30;
vector<vector<pi>> g;
ll jump[MAX][LOG_MAX];
ll mx[MAX][LOG_MAX];
ll depth[MAX];

void dfs(ll u, ll p = -1, ll d = 0) {
  depth[u] = d;
  jump[u][0] = p;
  for (auto &v : g[u]) {
    if (v.first == p) continue;
    mx[v.first][0] = v.second;
    dfs(v.first, u, d + 1);
  }
}

void build(ll n) {
  memset(jump, -1, sizeof jump);

  mx[0][0] = -INF;
  dfs(0);

  for (ll i = 1; i < LOG_MAX; i++)
    for (ll u = 0; u < n; u++)
      if (jump[u][i - 1] != -1) {
        jump[u][i] = jump[jump[u][i - 1]][i - 1];
        mx[u][i] = max(mx[u][i - 1], mx[jump[u][i - 1]][i - 1]);
      }
}

ll getMax(ll p, ll q) {
  if (depth[p] < depth[q]) swap(p, q);

  ll ans = 0;
  ll dist = depth[p] - depth[q];
  for (ll i = LOG_MAX - 1; i >= 0; i--)
    if ((dist >> i) & 1) ans = max(ans, mx[p][i]), p = jump[p][i];

  if (p == q) return ans;

  for (ll i = LOG_MAX - 1; i >= 0; i--)
    if (jump[p][i] != jump[q][i]) {
      ans = max(ans, mx[p][i]);
      ans = max(ans, mx[q][i]);
      p = jump[p][i];
      q = jump[q][i];
    }

  return max({ans, mx[p][0], mx[q][0]});
}

struct Edge {
  ll u, v, c, id;

  bool operator<(Edge e) const { return c < e.c; }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, m;
  cin >> n >> m;
  vector<Edge> edges(m);
  map<pi, ll> mapa;
  FOR(i, 0, m) {
    cin >> edges[i].u >> edges[i].v >> edges[i].c;
    edges[i].u--, edges[i].v--;
    mapa[{min(edges[i].u, edges[i].v), max(edges[i].v, edges[i].u)}] = i;
    edges[i].id = i;
  }
  sort(ALL(edges));
  DSU dsu;
  dsu.init(n);
  g.resize(n);
  vector<ll> inMST(m, 0);

  for (Edge e : edges) {
    if (dsu.get(e.u) != dsu.get(e.v)) {
      dsu.join(e.u, e.v);
      g[e.u].pb({e.v, e.c});
      g[e.v].pb({e.u, e.c});
      inMST[e.id] = 1;
    }
  }

  build(n);
  vi ans(m, INF);

  vector<set<pi>> alternativas(n);
  for (Edge e : edges) {
    if (inMST[e.id]) continue;
    ans[e.id] = getMax(e.u, e.v) - 1;
    alternativas[e.u].insert({e.c, e.id});
    alternativas[e.v].insert({e.c, e.id});
  }

  auto merge = [&](set<pi> &a, set<pi> &b) -> void {
    if (SZ(a) < SZ(b)) a.swap(b);
    for (pi p : b) {
      if (!a.count(p))
        a.insert(p);
      else
        a.erase(p);
    }
  };

  auto solve = [&](auto self, ll u, ll p = -1) -> ll {
    for (auto v : g[u]) {
      if (v.first == p) continue;
      ll res = self(self, v.first, u);
      ll id = mapa[{min(u, v.first), max(u, v.first)}];
      ans[id] = res - 1;
      merge(alternativas[u], alternativas[v.first]);
    }
    return (SZ(alternativas[u]) ? alternativas[u].begin()->first : INF + 10);
  };
  solve(solve, 0);
  FOR(i, 0, m) {
    if (ans[i] >= INF) ans[i] = -1;
  }
  FOR(i, 0, m) { cout << ans[i] << " \n"[i == m - 1]; }

  return 0;
}