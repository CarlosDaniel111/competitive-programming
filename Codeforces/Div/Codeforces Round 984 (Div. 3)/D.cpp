#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vi> grid(n, vi(m));
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      char c;
      cin >> c;
      grid[i][j] = c - '0';
    }
  }
  int nc = min(n, m) / 2;
  vector<vi> capas(nc);
  FOR(k, 0, nc) {
    FOR(i, k, m - k) { capas[k].pb(grid[k][i]); }
    FOR(i, k + 1, n - k - 1) { capas[k].pb(grid[i][m - k - 1]); }

    ROF(i, m - k, k) { capas[k].pb(grid[n - k - 1][i]); }
    ROF(i, n - k - 1, k + 1) { capas[k].pb(grid[i][k]); }
  }

  int ans = 0;

  for (auto &capa : capas) {
    int m = SZ(capa);
    FOR(i, 0, m) {
      if (capa[i] == 1 && capa[(i + 1) % m] == 5 && capa[(i + 2) % m] == 4 &&
          capa[(i + 3) % m] == 3)
        ans++;
    }
  }
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}