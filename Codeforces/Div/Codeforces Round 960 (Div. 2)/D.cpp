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
  FOR(i, 0, n) cin >> a[i];

  int ans = 0;
  bool b1 = false, b2 = false;
  FOR(i, 0, n) {
    if (!b1 && !b2) {
      if (a[i] == 0) continue;
      if (a[i] <= 2) b1 = 1;
      ans++;
    } else if (b1) {
      b1 = 0;
      if (a[i] <= 2) continue;
      if (a[i] <= 4) b2 = 1;
      ans++;
    } else {
      b2 = 0;
      if (a[i] == 0) continue;
      if (a[i] <= 4) b1 = 1;
      ans++;
    }
  }
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}