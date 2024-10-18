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

constexpr int INF = 1e7;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, k;
  cin >> n >> m >> k;
  vector<vi> g(n);
  FOR(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  int s1, t1, s2, t2;
  cin >> s1 >> t1 >> s2 >> t2;
  s1--, t1--, s2--, t2--;
  vector<vi> dist(n, vi(n, INF));

  auto bfs = [&](int ini) -> void {
    queue<int> q;
    dist[ini][ini] = 0;
    q.push(ini);
    while (SZ(q)) {
      int u = q.front();
      q.pop();
      for (auto v : g[u]) {
        if (dist[ini][v] > dist[ini][u] + 1) {
          dist[ini][v] = dist[ini][u] + 1;
          q.push(v);
        }
      }
    }
  };
  FOR(i, 0, n) bfs(i);

  vi len(n + 5, INF);
  FOR(u, 0, n) {
    FOR(v, 0, n) {
      int d = dist[u][v];
      if (d == INF) continue;
      len[d] =
          min(len[d], dist[s1][u] + dist[v][t1] + dist[s2][u] + dist[v][t2]);
      len[d] =
          min(len[d], dist[s1][v] + dist[u][t1] + dist[s2][u] + dist[v][t2]);
      len[d] =
          min(len[d], dist[s1][u] + dist[v][t1] + dist[s2][v] + dist[u][t2]);
      len[d] =
          min(len[d], dist[s1][v] + dist[u][t1] + dist[s2][v] + dist[u][t2]);
    }
  }
  len[0] = dist[s1][t1] + dist[s2][t2];

  auto f = [&](int l1, int l2, int k1, int k2) -> double {
    double res = 0;

    if (l1) {
      res += 2.0 * (l1 - k1 % l1) / (1 + k1 / l1);
      res += 2.0 * (k1 % l1) / (2 + k1 / l1);  // sobrante
    }
    if (l2) {
      res += 1.0 * (l2 - k2 % l2) / (1 + k2 / l2);
      res += 1.0 * (k2 % l2) / (2 + k2 / l2);  // sobrante
    }
    return res;
  };

  auto solve = [&](int l1, int l2) -> double {
    int l = 0, r = k;
    while (r - l > 10) {
      int m1 = l + (r - l) / 3;
      int m2 = r - (r - l + 2) / 3;
      double f1 = f(l1, l2, m1, k - m1);
      double f2 = f(l1, l2, m2, k - m2);
      if (f1 > f2)
        l = m1;
      else
        r = m2;
    }
    double res = INF;
    FOR(i, l, r + 1) res = min(res, f(l1, l2, i, k - i));
    return res;
  };

  double ans = INF;
  FOR(i, 0, n + 1) {
    if (len[i] == INF) continue;
    ans = min(ans, solve(i, len[i]));
  }
  cout << setprecision(9) << fixed;
  cout << ans << ENDL;

  return 0;
}