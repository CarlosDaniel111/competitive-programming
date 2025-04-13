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
  vi a(n);
  FOR(i, 0, n)
  cin >> a[i];
  int ans = 3e8;
  FOR(i, 1, a[0] + 1) {
    int mx = 0;
    FOR(j, 0, n) {
      int aux = min(k, a[j] / i);
      mx = max(mx, a[j] / aux);
    }
    ans = min(ans, mx - i);
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