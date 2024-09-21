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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  
  vector<vi> actors(n), movies(m);
  FOR (i, 0, n) {
    int k;
    cin >> k;
    while (k--) {
      int x;
      cin >> x;
      --x;
      actors[i].pb(x);
      movies[x].pb(i);
    }
  }

  vector<vi> g(n), mid(n, vi(n));
  FOR (i, 0, n) {
    vi in_movie(m);
    for (auto &x : actors[i]) in_movie[x] = 1;
    FOR (j, i + 1, n) for (auto &x : actors[j]) if (in_movie[x]) {
      g[i].pb(j), g[j].pb(i);
      mid[i][j] = mid[j][i] = x;
      break;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    queue<int> q;
    vi dist(n, -1), prev(n, -1);
    for (auto &x : movies[u]) q.push(x), dist[x] = 0;
    while (!q.empty()) {
      int fr = q.front();
      q.pop();
      for (auto &nei : g[fr]) if (dist[nei] == -1) {
        dist[nei] = dist[fr] + 1;
        prev[nei] = fr;
        q.push(nei);
      }
    }
    int curr = -1;
    for (auto &x : movies[v]) if (dist[x] != -1) {
      curr = x;
      break;
    }
    if (curr == -1) {
      cout << -1 << ENDL;
      continue;
    }
    cout << dist[curr] + 2 << ENDL;
    vi path_movies;
    while (curr != -1) {
      path_movies.pb(curr);
      curr = prev[curr];
    }
    reverse(ALL(path_movies));
    cout << u + 1;
    FOR (i, 0, SZ(path_movies) - 1) {
      cout << ' ' << path_movies[i] + 1 << ' ' << mid[path_movies[i]][path_movies[i + 1]] + 1;
    }
    cout << ' ' << path_movies.back() + 1 << ' ' << v + 1 << ENDL;
  }

  return 0;
}