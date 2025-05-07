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
  vi vis(n, 0);
  vi pos(n * m);
  vector<vi> deck(n, vi(m));
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      int x;
      cin >> x;
      deck[i][j] = x;
      pos[x] = i;
    }
  }
  vi ans;
  FOR(i, 0, n) {
    if (vis[pos[i]]) {
      cout << -1 << ENDL;
      return;
    }
    ans.pb(pos[i]);
    vis[pos[i]] = 1;
  }

  FOR(i, 0, n) {
    sort(ALL(deck[i]));
    FOR(j, 0, m - 1) {
      if (deck[i][j + 1] - deck[i][j] != n) {
        cout << -1 << ENDL;
        return;
      }
    }
  }

  for (auto x : ans) {
    cout << x + 1 << " ";
  }
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}