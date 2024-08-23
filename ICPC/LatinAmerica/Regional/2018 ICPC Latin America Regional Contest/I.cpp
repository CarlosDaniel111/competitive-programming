#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

vector<vi> g;
vi depth;

void dfs(int u, int d) {
  depth[u] = d;
  for (auto v : g[u]) dfs(v, d + 1);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vi p(n, 0);
  vi deg(n, 0);
  g.resize(n);
  FOR(i, 1, n) {
    cin >> p[i];
    p[i]--;
    deg[p[i]]++;
    g[p[i]].pb(i);
  }

  depth.assign(n, 0);
  dfs(0, 0);
  set<pi> s;
  FOR(i, 1, n) {
    s.insert({-depth[i], i});
  }
  int ans = 0;
  while (SZ(s)) {
    pi curr = (*s.begin());
    int u = curr.second;
    int v = p[u];
    s.erase(s.begin());
    pi padre = {-depth[v], v};
    if (deg[u] >= 2 && deg[v] >= 3 && v && s.find(padre) != s.end()) {
      ans++;
      deg[p[v]]--;
      s.erase(padre);
    }
  }
  cout << ans << ENDL;

  return 0;
}