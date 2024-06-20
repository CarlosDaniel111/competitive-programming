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

using piii = tuple<int, int, int>;
constexpr int INF = 5e8;
vector<vector<pi>> g;
priority_queue<piii, vector<piii>, greater<piii>> pq;
vector<vi> dist;

int out_angle[1005][1005];
int n, bird, a1, a2;

void dijkstra() {
  dist.assign(n, vi(360, INF));

  while (SZ(pq)) {
    auto [currw, u, in_ang] = pq.top();
    pq.pop();
    if (dist[u][in_ang] <= currw) continue;
    dist[u][in_ang] = currw;
    for (auto p : g[u]) {
      auto [v, w] = p;
      int out_ang = out_angle[u][v];
      int vuelta = (out_ang - in_ang + 360) % 360;
      if (vuelta > a1 && (360 - vuelta > a2)) continue;
      int llegada_ang = (180 + out_angle[v][u]) % 360;
      if (currw + w >= dist[v][llegada_ang]) continue;
      pq.push({currw + w, v, llegada_ang});
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n >> bird >> a1 >> a2;
  bird--;
  g.resize(n);
  FOR(i, 0, n) {
    int m;
    cin >> m;
    while (m--) {
      int v, w, ang;
      cin >> v >> w >> ang;
      v--;
      out_angle[i][v] = ang;
      g[i].pb({v, w});
    }
  }
  while (SZ(pq)) pq.pop();
  FOR(i, 0, 360) pq.push({0, 0, i});
  dijkstra();

  while (SZ(pq)) pq.pop();
  FOR(i, 0, 360) {
    int w = dist[bird][i];
    if (w < INF) {
      pq.push({w, bird, i});
    }
  }
  dijkstra();
  int ans = INF;
  FOR(i, 0, 360) { ans = min(ans, dist[0][i]); }
  if (ans == INF) {
    cout << "impossible" << ENDL;
  } else {
    cout << ans << ENDL;
  }

  return 0;
}