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
  string ans = "";
  int n, m;
  cin >> n >> m;
  FOR(i, 0, m)
  ans += 'B';
  FOR(i, 0, n) {
    int x;
    cin >> x;
    int opc1 = m + 1 - x;
    int opc2 = x;
    if (opc1 < opc2) {
      if (ans[opc1 - 1] == 'B') {
        ans[opc1 - 1] = 'A';
      } else {
        ans[opc2 - 1] = 'A';
      }
    } else {
      if (ans[opc2 - 1] == 'B') {
        ans[opc2 - 1] = 'A';
      } else {
        ans[opc1 - 1] = 'A';
      }
    }
  }
  cout << ans << ENDL;
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