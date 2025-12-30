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

vector<int> g[6];
int vis[6];

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<pi> pieces;
  pieces.reserve(21);
  FOR(i, 0, 6) FOR(j, i, 6) pieces.pb({i, j});
  vector<vector<int>> mp(6, vi(6, 0));
  FOR(i, 0, SZ(pieces)) mp[pieces[i].first][pieces[i].second] = i;

  const int N = 21;

  auto check = [&](int msk) -> bool {
    int root = 0;
    FOR(i, 0, N) {
      if ((msk >> i) & 1) {
        g[pieces[i].first].pb(pieces[i].second);
        g[pieces[i].second].pb(pieces[i].first);
        root = pieces[i].first;
      }
    }
    int cnt = 0, odd = 0;
    FOR(i, 0, 6) {
      odd += (SZ(g[i]) & 1);
      cnt += (SZ(g[i]) > 0);
    }
    auto dfs = [&](auto self, int u) -> void {
      vis[u] = 1;
      cnt--;
      for (auto v : g[u])
        if (!vis[v]) self(self, v);
    };
    dfs(dfs, root);
    FOR(i, 0, 6) {
      vis[i] = 0;
      g[i].clear();
    }
    return (cnt == 0 && odd <= 2);
  };

  const int LIM = 1 << N;
  vector<int> f(LIM);
  FOR(msk, 1, LIM) { f[msk] = check(msk); }

  for (int i = 0; i < N; ++i)
    for (int mask = 0; mask < (1 << N); ++mask) {
      if (mask & (1 << i)) f[mask] += f[mask ^ (1 << i)];
    }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int msk = 0;
    FOR(i, 0, n) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      msk += 1 << mp[u][v];
    }
    cout << f[msk] << ENDL;
  }

  return 0;
}