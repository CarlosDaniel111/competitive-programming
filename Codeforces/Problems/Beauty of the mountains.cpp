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
  int n, m, k;
  cin >> n >> m >> k;
  vector<vi> a(n, vi(m));
  FOR(i, 0, n) FOR(j, 0, m) cin >> a[i][j];
  vector<vector<char>> b(n, vector<char>(m));
  ll diff = 0;
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      cin >> b[i][j];
      diff += a[i][j] * (b[i][j] == '1' ? 1 : -1);
    }
  }
  if (diff == 0) {
    cout << "YES" << ENDL;
    return;
  }
  vector<vi> pref(n + 1, vi(m + 1, 0));
  FOR(i, 1, n + 1) {
    FOR(j, 1, m + 1) {
      pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] +
                   (b[i - 1][j - 1] == '1' ? 1 : -1);
    }
  }

  ll g = 0;
  FOR(i, 0, n - k + 1) {
    FOR(j, 0, m - k + 1) {
      ll d = pref[i + k][j + k] - pref[i + k][j] - pref[i][j + k] + pref[i][j];
      g = gcd(g, d);
    }
  }
  if (g && diff % g == 0) {
    cout << "YES" << ENDL;
  } else {
    cout << "NO" << ENDL;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}