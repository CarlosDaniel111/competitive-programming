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
  FOR(i, 0, n) {
    cin >> a[i];
    FOR(_, 1, a[i]) {
      int x;
      cin >> x;
    }
  }
  ll ans = 0;
  ROF(i, 31, 0) {
    int cnt = 0;
    FOR(j, 0, n) { cnt += (a[j] >> i) & 1; }
    if (cnt >= 2) {
      ans += (1 << (i + 1)) - 1;
      break;
    } else if (cnt == 1) {
      ans += (1 << i);
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