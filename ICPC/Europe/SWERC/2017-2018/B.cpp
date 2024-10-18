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

  int x, y, n, m;
  cin >> x >> y >> n >> m;
  vector<vi> vis(x + 5, vi(y + 5, 0));
  vector<vi> ans(x + 5, vi(y + 5, 0));
  FOR(_, 0, n) {
    int lx, rx, ly, ry;
    cin >> lx >> rx >> ly >> ry;
    FOR(i, lx + 1, rx + 1) {
      FOR(j, ly + 1, ry + 1) { vis[i][j] = 1; }
    }
  }
  FOR(i, 1, x + 1) vis[i][y + 1] = 1;

  vi height(y + 1, 0);
  FOR(i, 1, x + 1) {
    stack<pi> st;
    while (SZ(st)) st.pop();
    FOR(j, 1, y + 2) {
      if (vis[i][j])
        height[j] = 0;
      else
        height[j]++;

      int ant = j;
      while (SZ(st) && st.top().first >= height[j]) {
        ans[st.top().first][j - ant]--;
        ant = st.top().second;
        ans[st.top().first][j - ant]++;
        st.pop();
      }
      ans[height[j]][j - ant]--;
      st.push({height[j], ant});
    }
  }

  ROF(i, x + 1, 0) {
    ROF(j, y, 0) ans[i][j] += ans[i][j + 1];
    ROF(j, y, 0) ans[i][j] += ans[i][j + 1];
  }
  ROF(i, x, 0) { ROF(j, y + 1, 0) ans[i][j] += ans[i + 1][j]; }

  // FOR(i, 1, x + 1) {
  //   FOR(j, 1, y + 1) { cout << vis[i][j] << " "; }
  //   cout << ENDL;
  // }
  // cout << ENDL;

  // FOR(i, 1, x + 1) {
  //   FOR(j, 1, y + 1) { cout << ans[i][j] << " "; }
  //   cout << ENDL;
  // }

  FOR(i, 0, m) {
    int a, b;
    cin >> a >> b;
    cout << ans[a][b] << ENDL;
  }

  return 0;
}