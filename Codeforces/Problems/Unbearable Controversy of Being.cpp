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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vi> g(n, vi());
  vector<vi> mat(n, vi(n, 0));
  FOR(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    mat[u][v] = 1;
  }

  ll ans = 0;
  FOR(a, 0, n) {
    FOR(c, 0, n) {
      if (a == c) continue;
      int r = 0;
      for (auto b : g[a]) {
        r += (mat[b][c]);
      }
      ans += r * (r - 1) / 2;
    }
  }
  cout << ans << ENDL;

  return 0;
}