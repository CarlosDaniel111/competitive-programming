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
  vi b(n - 1);
  FOR(i, 0, n - 1) cin >> b[i];
  vi a(n, 0);
  a[0] = b[0];

  a[n - 1] = b[n - 2];

  FOR(i, 1, n - 1) {
    FOR(k, 0, 31) {
      if (((b[i] >> k) & 1) || ((b[i - 1] >> k) & 1)) {
        a[i] |= (1 << k);
      }
    }
  }

  FOR(i, 0, n - 1) {
    // cout << (a[i] & a[i + 1]) << ENDL;
    if ((a[i] & a[i + 1]) != b[i]) {
      cout << -1 << ENDL;
      return;
    }
  }

  for (auto x : a) {
    cout << x << " ";
  }
  cout << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}