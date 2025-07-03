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

constexpr int MAX = 1e5 + 5;

vector<int> g[MAX];
vector<pi> anc[MAX];
int taken[MAX];
int sz[MAX];
int closest[MAX];

int calcsz(int u, int p = -1) {
  sz[u] = 1;
  for (auto v : g[u])
    if (v != p && !taken[v]) sz[u] += calcsz(v, u);
  return sz[u];
}

void addAncestor(int u, int d, int centroid, int p = -1) {
  anc[u].pb({centroid, d});
  for (auto v : g[u])
    if (!taken[v] && v != p) addAncestor(v, d + 1, centroid, u);
}

void decompose(int u, int globalSz = -1) {
  if (globalSz == -1) globalSz = calcsz(u);
  for (auto v : g[u])
    if (!taken[v] && sz[v] * 2 >= globalSz) {
      sz[u] = 0;
      decompose(v, globalSz);
      return;
    }
  taken[u] = 1;
  addAncestor(u, 0, u);

  for (auto v : g[u])
    if (!taken[v]) decompose(v);
}

void update(int u) {
  for (auto &[p, d] : anc[u]) {
    closest[p] = min(closest[p], d);
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  FOR(i, 1, n) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  FOR(i, 1, n) closest[i] = 1e7;
  decompose(0);
  update(0);

  while (q--) {
    int t, u;
    cin >> t >> u;
    u--;
    if (t == 1) {
      closest[u] = 0;
      update(u);
      continue;
    }
    int ans = closest[u];
    for (auto &[p, d] : anc[u]) {
      ans = min(ans, closest[p] + d);
    }
    cout << ans << ENDL;
  }

  return 0;
}