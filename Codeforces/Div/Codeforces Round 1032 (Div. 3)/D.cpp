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
  vi a(n), b(n);
  FOR(i, 0, n) cin >> a[i];
  FOR(i, 0, n) cin >> b[i];

  vector<pi> ans;
  FOR(i, 0, n) {
    if (a[i] > b[i]) {
      ans.pb({3, i + 1});
      swap(a[i], b[i]);
    }
  }
  FOR(i, 0, n) {
    FOR(j, 0, n - 1) {
      if (a[j] > a[j + 1]) {
        ans.pb({1, j + 1});
        swap(a[j], a[j + 1]);
      }
      if (b[j] > b[j + 1]) {
        ans.pb({2, j + 1});
        swap(b[j], b[j + 1]);
      }
    }
  }
  assert(SZ(ans) <= 1709);
  cout << SZ(ans) << ENDL;
  for (auto [x, y] : ans) {
    cout << x << " " << y << ENDL;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}