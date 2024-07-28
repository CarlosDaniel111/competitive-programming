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
  int n, k;
  cin >> n >> k;
  vector<vector<char>> a(n, vector<char>(n));
  FOR(i, 0, n) {
    FOR(j, 0, n) { cin >> a[i][j]; }
  }
  int m = n / k;
  vector<vector<char>> ans(m, vector<char>(m));
  for (int i = 0; i < n; i += k) {
    for (int j = 0; j < n; j += k) {
      cout << a[i][j];
    }
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