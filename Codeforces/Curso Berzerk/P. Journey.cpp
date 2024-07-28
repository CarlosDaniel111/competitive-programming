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

vector<double> ans;
vector<vi> g;
ll suma = 0;
ll n;

void dfs(int u, int p) {
  double suma = 0;
  int cnt = 0;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    suma += ans[v];
    cnt++;
  }
  if (cnt) ans[u] = suma / cnt * 1.0 + 1;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n;
  g.assign(n, vi());
  ans.assign(n, 0);
  FOR(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(0, -1);
  cout << setprecision(9) << fixed;
  cout << ans[0] << ENDL;

  return 0;
}