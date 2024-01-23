#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

constexpr int INF = 5e8;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, o, c;
  cin >> n >> o >> c;
  vector<vi> g(n, vi());
  vector<vi> g2(n, vi());
  queue<int> qo, qc, q;
  vi disto(n, INF), distc(n, INF), dist(n, INF);
  FOR(i, 0, o) {
    int x;
    cin >> x;
    x--;
    qo.push(x);
    disto[x] = 0;
  }
  FOR(i, 0, c) {
    int x;
    cin >> x;
    x--;
    qc.push(x);
    distc[x] = 0;
  }
  FOR(i, 0, n) {
    int k;
    cin >> k;
    while (k--) {
      int x;
      cin >> x;
      x--;
      g[i].pb(x);
      g2[x].pb(i);
    }
  }

  while (SZ(qo)) {
    int u = qo.front();
    qo.pop();

    for (auto v : g2[u]) {
      if (disto[v] == INF) {
        disto[v] = disto[u] + 1;
        qo.push(v);
      }
    }
  }

  while (SZ(qc)) {
    int u = qc.front();
    qc.pop();

    for (auto v : g2[u]) {
      if (distc[v] == INF) {
        distc[v] = distc[u] + 1;
        qc.push(v);
      }
    }
  }
  q.push(0);
  dist[0] = 0;

  while (SZ(q)) {
    int u = q.front();
    q.pop();

    for (auto v : g[u]) {
      if (dist[v] == INF) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }

  int ans = INF;
  FOR(i, 0, n) {
    int curr = dist[i] + distc[i] + disto[i];
    ans = min(ans, curr);
  }
  if (ans >= INF) {
    cout << "impossible" << ENDL;
  } else
    cout << ans << ENDL;

  return 0;
}