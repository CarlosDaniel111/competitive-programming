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

constexpr int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vi> grid(n, vi(m, 0));
  FOR(i, 0, n) {
    FOR(j, 0, m) { cin >> grid[i][j]; }
  }

  bool cambio = true;

  while (cambio) {
    cambio = false;
    FOR(i, 0, n) {
      FOR(j, 0, m) {
        int aux = -1, cnt = 0;
        FOR(k, 0, 4) {
          int x = i + dx[k], y = j + dy[k];
          if (x >= 0 && x < n && y >= 0 && y < m && grid[i][j] > grid[x][y]) {
            aux = max(aux, grid[x][y]);
            cnt++;
          }
          cnt += !(x >= 0 && x < n && y >= 0 && y < m);
        }
        if (cnt == 4) {
          grid[i][j] = aux;
          cambio = true;
        }
      }
    }
  }
  FOR(i, 0, n) {
    FOR(j, 0, m) { cout << grid[i][j] << " "; }
    cout << ENDL;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}