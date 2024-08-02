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

struct Edge {
  int v;
  double A, B;
  double eval(double t) {
    return A * t * 1.0 + B;
  }
};

vector<vector<Edge>> g;
int n;
constexpr double INF = 3e9;

double dijkstra(double t) {
  vector<double> dist(n, INF);
  dist[0] = 0;
  priority_queue<pair<double, int>> pq;
  pq.emplace(0, 0);
  while (!pq.empty()) {
    pair<double, int> top = pq.top();
    double du = top.first;
    int u = top.second;
    du *= -1;
    pq.pop();

    if (du > dist[u])
      continue;

    for (auto &edge : g[u]) {
      double dv = edge.eval(t);
      int v = edge.v;
      if (du + dv < dist[v]) {
        dist[v] = du + dv;
        pq.emplace(-dist[v], v);
      }
    }
  }
  return dist[n - 1];
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int m;
  cin >> n >> m;
  g.resize(n);
  FOR(i, 0, m) {
    int u, v;
    double A, B;
    cin >> u >> v >> A >> B;
    u--, v--;
    g[u].pb({v, A, B});
    g[v].pb({u, A, B});
  }
  double l = 0, r = 24 * 60;
  FOR(_, 0, 200) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    double f1 = dijkstra(m1);
    double f2 = dijkstra(m2);
    if (f1 < f2)  // Maximo de f(x)
      l = m1;
    else
      r = m2;
  }
  cout << setprecision(5) << fixed;
  cout << dijkstra(l) << ENDL;

  return 0;
}