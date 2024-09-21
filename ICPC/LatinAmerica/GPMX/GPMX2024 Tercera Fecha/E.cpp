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

  int n;
  cin >> n;
  vector<vi> a(n, vi(n));
  FOR (i, 0, n) FOR (j, 0, n) cin >> a[i][j];

  FOR (k, 0, 4) {
    bool ok = 1;
    FOR (i, 0, n) {
      FOR (j, 0, n) {
        ok &= i == 0 || a[i-1][j] < a[i][j];
        ok &= j == 0 || a[i][j-1] < a[i][j];
      }
    }
    if (ok) {
      cout << k << ENDL;
      return 0;
    }
    vector<vi> b(n, vi(n));
    FOR (i, 0, n) {
      FOR (j, 0, n) {
        b[n - j - 1][i] = a[i][j];
      }
    }
    a.swap(b);
  }

  return 0;
}