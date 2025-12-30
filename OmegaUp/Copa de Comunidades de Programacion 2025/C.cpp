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

struct Bot {
  ll x, a, f, p;
};
struct Brecha {
  ll y, d, g;
};

const ll INF2 = 1e18 + 5;

template <typename T>
struct Dinic {
#define INF numeric_limits<T>::max()
  struct Edge {
    ll to, rev;
    T c, oc;
    T flow() { return max(oc - c, T(0)); }  // if you need flows
  };
  vi lvl, ptr, q;
  vector<vector<Edge>> adj;
  Dinic(ll n) : lvl(n), ptr(n), q(n), adj(n) {}
  void addEdge(ll a, ll b, T c = INF, T rcap = 0) {
    adj[a].push_back({b, SZ(adj[b]), c, c});
    adj[b].push_back({a, SZ(adj[a]) - 1, rcap, rcap});
  }
  T dfs(ll v, ll t, T f) {
    if (v == t || !f) return f;
    for (ll& i = ptr[v]; i < SZ(adj[v]); i++) {
      Edge& e = adj[v][i];
      if (lvl[e.to] == lvl[v] + 1)
        if (T p = dfs(e.to, t, min(f, e.c))) {
          e.c -= p, adj[e.to][e.rev].c += p;
          return p;
        }
    }
    return 0;
  }
  T calc(ll s, ll t) {
    T flow = 0;
    q[0] = s;
    FOR(L, 0, 31) do {  // 'll L=30' maybe faster for random data
      lvl = ptr = vi(SZ(q));
      ll qi = 0, qe = lvl[s] = 1;
      while (qi < qe && !lvl[t]) {
        ll v = q[qi++];
        for (Edge e : adj[v])
          if (!lvl[e.to] && e.c >> (30 - L))
            q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
      }
      while (T p = dfs(s, t, INF)) flow += p;
    }
    while (lvl[t]);
    return flow;
  }
  bool leftOfMinCut(ll a) { return lvl[a] != 0; }
};

vector<ll> getSCC(vector<vector<ll>>& g) {
  ll n = ll(g.size()), t = 0, ncomps = 0;
  vector<ll> tin(n), scc(n, -1), z;
  auto dfs = [&](auto&& self, ll u) -> ll {
    ll low = tin[u] = ++t, x;
    z.push_back(u);
    for (auto v : g[u])
      if (scc[v] < 0) low = min(low, tin[v] ?: self(self, v));
    if (low == tin[u]) {
      do {
        x = z.back();
        z.pop_back();
        scc[x] = ncomps;
      } while (x != u);
      ncomps++;
    }
    return tin[u] = low;
  };
  for (ll i = 0; i < n; ++i)
    if (scc[i] == -1) dfs(dfs, i);
  return scc;
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
    g[v].pb(u);
  }
  ll s, b, k;
  cin >> s >> b >> k;
  vector<Bot> bots(s);
  FOR(i, 0, s) {
    cin >> bots[i].x >> bots[i].a >> bots[i].f >> bots[i].p;
    bots[i].x--;
  }
  vector<Brecha> brechas(b);
  vector<vector<pi>> dxn(n);
  FOR(i, 0, b) {
    cin >> brechas[i].y >> brechas[i].d >> brechas[i].g;
    brechas[i].y--;
    dxn[brechas[i].y].pb({brechas[i].d, brechas[i].g});
  }
  FOR(i, 0, n) {
    sort(ALL(dxn[i]));
    ll nn = SZ(dxn[i]);
    FOR(j, 1, nn) {
      dxn[i][j].second = max(dxn[i][j].second, dxn[i][j - 1].second);
    }
  }

  auto bfs = [&](ll start) -> vector<ll> {
    queue<ll> q;
    vi dist(n, INF2);
    q.push(start);
    dist[start] = 0;
    while (SZ(q)) {
      ll u = q.front();
      q.pop();
      for (auto v : g[u]) {
        if (dist[v] > dist[u] + 1) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
    return dist;
  };

  vector<vi> dist(s);
  FOR(i, 0, s) { dist[i] = bfs(bots[i].x); }

  vi ganancia(s, -INF2);
  FOR(i, 0, s) {
    FOR(v, 0, n) {
      if (dist[i][v] > bots[i].f) continue;
      ll pos = upper_bound(ALL(dxn[v]), make_pair(bots[i].a, -INF2)) -
               dxn[v].begin();
      pos--;
      if (pos == -1) continue;
      ganancia[i] = max(ganancia[i], dxn[v][pos].second - bots[i].p);
    }
    if (ganancia[i] == -INF2) ganancia[i] = 0;
  }
  vector<vi> g2(s);
  FOR(i, 0, k) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g2[u].pb(v);
  }

  vector<ll> scc = getSCC(g2);
  ll comp = ll(*max_element(scc.begin(), scc.end())) + 1;
  vector<set<ll>> rg(comp);
  vector<ll> val(comp);
  for (ll u = 0; u < s; ++u) {
    val[scc[u]] += ganancia[u];
    for (ll v : g[u]) {
      if (scc[u] != scc[v]) {
        rg[scc[v]].insert(scc[u]);
      }
    }
  }

  ll ans = 0;
  Dinic<ll> dinic(comp + 2);
  for (ll i = 0; i < comp; ++i) {
    if (val[i] <= 0) {
      dinic.addEdge(i, comp + 1, -val[i]);
      continue;
    }
    dinic.addEdge(comp, i, val[i]);
    ans += val[i];
    auto dfs = [&](auto&& dfs, ll u, set<ll>& vis) -> void {
      if (vis.count(u)) return;
      vis.insert(u);
      if (val[u] < 0) {
        dinic.addEdge(i, u);
      }
      for (ll v : rg[u]) {
        dfs(dfs, v, vis);
      }
    };
    set<ll> vis;
    dfs(dfs, i, vis);
  }
  ans -= dinic.calc(comp, comp + 1);
  cout << ans << '\n';

  return 0;
}