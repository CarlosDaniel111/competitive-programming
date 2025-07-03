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
  int n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n) { cin >> a[i]; }
  sort(ALL(a));
  int ans = n + 1;
  FOR(i, 0, n) {
    if (a[0] % 2 == a[n - i - 1] % 2) {
      ans = i;
      break;
    }
  }
  FOR(i, 0, n) {
    if (a[n - 1] % 2 == a[i] % 2) {
      ans = min(ans, i);
    }
  }
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}