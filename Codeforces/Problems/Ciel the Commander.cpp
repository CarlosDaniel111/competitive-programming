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

const int MAX = 1e5 + 5;

int n;
vi g[MAX];
int szt[MAX], vis[MAX];
char ans[MAX];
int calcsz(int u, int p = -1) {
  szt[u] = 1;
  for (auto v : g[u])
    if (v != p && !vis[v]) {
      szt[u] += calcsz(v, u);
    }
  return szt[u];
}
void centroid(char c, int u = 0, int p = -1, int sz = -1) {
  if (c > 'Z') {
    cout << "Impossible!" << ENDL;
    exit(0);
  }
  if (sz == -1) sz = calcsz(u);
  for (auto v : g[u])
    if (!vis[v] && szt[v] * 2 >= sz) {
      szt[u] = 0;
      centroid(c, v, p, sz);
      return;
    }
  ans[u] = c;
  vis[u] = 1;
  for (auto v : g[u])
    if (!vis[v]) {
      centroid(c + 1, v, u);
    }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  FOR(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  memset(vis, 0, sizeof(vis));

  centroid('A');
  FOR(i, 0, n) { cout << ans[i] << " "; }

  return 0;
}