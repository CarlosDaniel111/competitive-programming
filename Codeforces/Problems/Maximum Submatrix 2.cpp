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

  int n, m;
  cin >> n >> m;
  vector<vi> a(n, vi(m, 0));
  FOR(i, 0, n) {
    string s;
    cin >> s;
    FOR(j, 0, m) {
      a[i][j] = (s[j] == '1');
      if (j != 0 && s[j] == '1' && s[j - 1] == '1') a[i][j] += a[i][j - 1];
    }
  }
  int ans = 0;
  ROF(i, m, 0) {
    vi cnt(m + 1, 0);
    int curr = 0;
    FOR(j, 0, n) { curr++, cnt[a[j][i] + 1]--; }
    FOR(j, 1, m + 1) {
      curr += cnt[j];
      ans = max(ans, j * curr);
    }
  }
  cout << ans << ENDL;

  return 0;
}