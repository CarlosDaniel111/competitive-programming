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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vi> a(n, vi(m));
  FOR(i, 0, n) FOR(j, 0, m) cin >> a[i][j];
  vector<pi> pos(n * m + 1);
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      int x;
      cin >> x;
      pos[x] = {i, j};
    }
  }
  vi movei(n, -1), movej(m, -1);
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (movei[i] != -1 && movei[i] != pos[a[i][j]].first) {
        cout << "NO" << ENDL;
        return;
      }

      if (movej[j] != -1 && movej[j] != pos[a[i][j]].second) {
        cout << "NO" << ENDL;
        return;
      }
      movei[i] = pos[a[i][j]].first;
      movej[j] = pos[a[i][j]].second;
    }
  }
  cout << "YES" << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}