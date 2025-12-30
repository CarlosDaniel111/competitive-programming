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

  vi a(4);
  FOR(i, 0, 4) { cin >> a[i]; }
  int ans = 1e9;
  FOR(msk, 0, (1 << 4)) {
    int sum1 = 0, sum2 = 0, cnt = 0;
    FOR(k, 0, 4) {
      if ((msk >> k) & 1) {
        sum1 += a[k];
        cnt++;
      } else {
        sum2 += a[k];
      }
    }
    if (cnt == 2) {
      ans = min(ans, abs(sum1 - sum2));
    }
  }
  cout << ans << ENDL;

  return 0;
}