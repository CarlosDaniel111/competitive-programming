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
  vector<string> grid(n);
  FOR(i, 0, n) {
    cin >> grid[i];
  }

  // checar blancos
  bool ok[4][2];
  memset(ok, false, sizeof(ok));
  FOR(i, 0, m) {
    if (grid[0][i] == 'W') {
      ok[0][0] = true;
    } else {
      ok[0][1] = true;
    }
  }

  FOR(i, 0, m) {
    if (grid[n - 1][i] == 'W') {
      ok[1][0] = true;
    } else {
      ok[1][1] = true;
    }
  }

  FOR(i, 0, n) {
    if (grid[i][0] == 'W') {
      ok[2][0] = true;
    } else {
      ok[2][1] = true;
    }
  }

  FOR(i, 0, n) {
    if (grid[i][m - 1] == 'W') {
      ok[3][0] = true;
    } else {
      ok[3][1] = true;
    }
  }

  if (ok[0][0] && ok[1][0] && ok[2][0] && ok[3][0]) {
    cout << "YES" << ENDL;
  } else if (ok[0][1] && ok[1][1] && ok[2][1] && ok[3][1]) {
    cout << "YES" << ENDL;
  } else {
    cout << "NO" << ENDL;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}