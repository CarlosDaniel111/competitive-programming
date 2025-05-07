#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

const ll INF = numeric_limits<ll>::max() / 4;
const ll INF2 = 1e8;

struct MCMF {
  struct edge {
    int from, to, rev;
    ll cap, cost, flow;
  };
  int N;
  vector<vector<edge>> ed;
  vi seen;
  vector<ll> dist, pi;
  vector<edge*> par;

  MCMF(int N) : N(N), ed(N), seen(N), dist(N), pi(N), par(N) {}

  void addEdge(int from, int to, ll cap, ll cost) {
    if (from == to) return;
    ed[from].push_back(edge{from, to, int(ed[to].size()), cap, cost, 0});
    ed[to].push_back(edge{to, from, int(ed[from].size()) - 1, 0, -cost, 0});
  }

  void path(int s) {
    fill(seen.begin(), seen.end(), 0);
    fill(dist.begin(), dist.end(), INF);
    dist[s] = 0;
    ll di;

    __gnu_pbds::priority_queue<pair<ll, int>> q;
    vector<decltype(q)::point_iterator> its(N);
    q.push({0, s});

    while (!q.empty()) {
      s = q.top().second;
      q.pop();
      seen[s] = 1;
      di = dist[s] + pi[s];
      for (edge& e : ed[s])
        if (!seen[e.to]) {
          ll val = di - pi[e.to] + e.cost;
          if (e.cap - e.flow > 0 && val < dist[e.to]) {
            dist[e.to] = val;
            par[e.to] = &e;
            if (its[e.to] == q.end())
              its[e.to] = q.push({-dist[e.to], e.to});
            else
              q.modify(its[e.to], {-dist[e.to], e.to});
          }
        }
    }
    for (int i = 0; i < N; ++i) pi[i] = min(pi[i] + dist[i], INF);
  }

  pair<ll, ll> calc(int s, int t) {
    ll totflow = 0, totcost = 0;
    while (path(s), seen[t]) {
      ll fl = INF;
      for (edge* x = par[t]; x; x = par[x->from])
        fl = min(fl, x->cap - x->flow);

      totflow += fl;
      for (edge* x = par[t]; x; x = par[x->from]) {
        x->flow += fl;
        ed[x->to][x->rev].flow -= fl;
      }
    }
    for (int i = 0; i < N; ++i)
      for (edge& e : ed[i]) totcost += e.cost * e.flow;
    return {totflow, totcost / 2};
  }

  void setpi(int s) {
    fill(pi.begin(), pi.end(), INF);
    pi[s] = 0;
    int it = N, ch = 1;
    ll v;
    while (ch-- && it--)
      for (int i = 0; i < N; ++i)
        if (pi[i] != INF)
          for (edge& e : ed[i])
            if (e.cap)
              if ((v = pi[i] + e.cost) < pi[e.to]) pi[e.to] = v, ch = 1;
    assert(it >= 0);  // ciclo de costo negativo
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, q;
  cin >> n >> m >> q;
  vector<vi> a(n, vi(m));
  MCMF mfmc(2005);
  const int SOURCE = 2000, SINK = 2001;
  int ans = 0;
  auto getID = [&](int x, int y) -> int { return x * m + y; };
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
      if (a[i][j]) {
        int w = a[i][j] - 1;
        ans += w;
        int v = getID(i, j);
        mfmc.addEdge(v, v + n * m, w, -1);
        mfmc.addEdge(v, v + n * m, 8 - w, 1);
      }
    }
  }
  int entrada = 0, salida = 0;
  FOR(idx, 0, q) {
    char c;
    int x, y, s;
    cin >> c >> x >> y >> s;
    x--, y--;
    int nodoC = 2 * n * m + idx;
    if (c == 'H') {
      for (int i = y + 1; i < m && a[x][i]; i++) {
        mfmc.addEdge(nodoC, getID(x, i), INF2, 0);
        s--;
      }
      mfmc.addEdge(SOURCE, nodoC, s, 0);
      entrada += s;
    } else {
      for (int i = x + 1; i < n && a[i][y]; i++) {
        mfmc.addEdge(getID(i, y) + n * m, nodoC, INF2, 0);
        s--;
      }
      mfmc.addEdge(nodoC, SINK, s, 0);
    }
  }
  auto [flujo, costo] = mfmc.calc(SOURCE, SINK);
  if (flujo != entrada) {
    cout << "IMPOSSIBLE" << ENDL;
    return 0;
  }
  cout << ans + costo << ENDL;

  return 0;
}