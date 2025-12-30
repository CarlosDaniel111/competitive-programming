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
  ll sum = 0, mn = 0, mni = 0;
  FOR(i, 0, n) {
    cin >> a[i];
    sum += a[i];
    if (sum < mn) {
      mn = sum;
      mni = i;
    }
  }
  if (mn == 0) {
    cout << sum << ENDL;
    return;
  }
  ll ans = abs(mn);
  FOR(i, mni + 1, n) ans += a[i];
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}