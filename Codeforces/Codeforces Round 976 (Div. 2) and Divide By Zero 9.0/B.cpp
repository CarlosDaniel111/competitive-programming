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
// 3 8 15 24 35
void solve() {
  FOR(i, 1, 50) {
    vi a(i, 1);
    FOR(j, 1, i + 1) {
      FOR(k, 0, i) {
        if ((k + 1) % j == 0) {
          a[k] = a[k] xor 1;
        }
      }
    }
    int cnt = 0;
    FOR(j, 0, i) if (a[j]) cnt++;
    // FOR(j, 0, i) { cout << a[j] << " "; }
    cout << i << " " << cnt << ENDL;
  }
}
// 2 6 12 20

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}