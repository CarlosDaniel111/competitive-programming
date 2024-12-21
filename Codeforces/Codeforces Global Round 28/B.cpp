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
  vi ans(n, -1);
  int curr = 1;
  for (int i = k - 1; i < n; i += k) {
    ans[i] = curr++;
  }
  FOR(i, 0, n) {
    if (ans[i] == -1) ans[i] = curr++;
  }
  FOR(i, 0, n) cout << ans[i] << " \n"[i == n - 1];
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}