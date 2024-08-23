#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define ALL(x) (x.begin(), x.end())
#define SZ(x) ((int)x.size())
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; i++)
#define ENDL '\n'

vector<vi> g;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  g.assign(n, vi(n, 0));
  FOR(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u][v] = true;
    g[v][u] = true;
  }

  if (n == 1) {
    cout << "NO" << ENDL;
    return 0;
  }
  cout << "YES" << ENDL;

  vector<pi> ans;
  FOR(u, 0, n / 2) {
    FOR(v, 0, n / 2) {
      if (u == v) continue;
      if (!g[u][v]) {
        ans.pb({min(u, v), max(u, v)});
        g[u][v] = true;
        g[v][u] = true;
      }
    }
  }

  FOR(u, n / 2, n) {
    FOR(v, n / 2, n) {
      if (u == v) continue;
      if (!g[u][v]) {
        ans.pb({min(u, v), max(u, v)});
        g[u][v] = true;
        g[v][u] = true;
      }
    }
  }
  cout << SZ(ans) << ENDL;
  for (auto x : ans) {
    cout << x.first + 1 << " " << x.second + 1 << ENDL;
  }
  return 0;
}