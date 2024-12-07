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

constexpr int INF = 1e9;
constexpr int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<string> grid(n);
  FOR(i, 0, n) { cin >> grid[i]; }

  vector<vi> mxcrate(n, vi(n, INF));

  queue<pi> q;
  FOR(i, 0, n) {
    FOR(j, 0, n) {
      if (grid[i][j] == '#') {
        q.push({i, j});
        mxcrate[i][j] = 0;
      }
    }
  }

  FOR(i, 0, n) {
    q.push({i, 0});
    mxcrate[i][0] = 1;
    q.push({0, i});
    mxcrate[0][i] = 1;

    q.push({i, n - 1});
    mxcrate[i][n - 1] = 1;
    q.push({n - 1, i});
    mxcrate[n - 1][i] = 1;
  }

  auto isValid = [&](int x, int y) -> bool {
    return (x >= 0 && x < n && y >= 0 && y < n);
  };

  while (SZ(q)) {
    auto [ux, uy] = q.front();
    q.pop();
    FOR(k, 0, 4) {
      int vx = ux + dx[k], vy = uy + dy[k];
      if (!isValid(vx, vy)) continue;
      if (mxcrate[ux][uy] + 2 < mxcrate[vx][vy]) {
        mxcrate[vx][vy] = mxcrate[ux][uy] + 2;
        q.push({vx, vy});
      }
    }
  }

  FOR(i, 0, n) {
    FOR(j, 0, n) { cout << mxcrate[i][j] << " "; }
    cout << ENDL;
  }

  return 0;
}