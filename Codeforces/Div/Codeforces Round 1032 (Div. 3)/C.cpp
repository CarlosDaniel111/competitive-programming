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
  vector<vi> a(n, vi(m));
  FOR(i, 0, n) FOR(j, 0, m) cin >> a[i][j];

  pi mx = {0, 0};
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (a[i][j] > a[mx.first][mx.second]) {
        mx = {i, j};
      }
    }
  }

  // Bajar fila i
  pi mx2 = {0, 0};
  int aux = -1;
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (i == mx.first) {
        a[i][j]--;
      }
      if (a[i][j] > aux) {
        mx2 = {i, j};
        aux = a[i][j];
      }

      if (i == mx.first) {
        a[i][j]++;
      }
    }
  }
  // Usamos colum j de mx2
  int ans1 = 0;
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (i == mx.first or j == mx2.second) {
        a[i][j]--;
      }
      ans1 = max(ans1, a[i][j]);
      if (i == mx.first or j == mx2.second) {
        a[i][j]++;
      }
    }
  }

  // Bajar colum j
  mx2 = {0, 0};
  aux = -1;
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (j == mx.second) {
        a[i][j]--;
      }
      if (a[i][j] > aux) {
        mx2 = {i, j};
        aux = a[i][j];
      }

      if (j == mx.second) {
        a[i][j]++;
      }
    }
  }
  // Usamos fila i de mx2
  int ans2 = 0;
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (i == mx2.first or j == mx.second) {
        a[i][j]--;
      }
      ans2 = max(ans2, a[i][j]);
      if (i == mx2.first or j == mx.second) {
        a[i][j]++;
      }
    }
  }
  cout << min(ans1, ans2) << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}