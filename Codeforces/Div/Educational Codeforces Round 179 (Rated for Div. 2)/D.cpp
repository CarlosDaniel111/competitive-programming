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
  int n, m;
  cin >> n >> m;
  vi a(m);
  FOR(i, 0, m) cin >> a[i];
  sort(ALL(a));
  FOR(i, 0, n) {
    FOR(_, 0, 3) {
      if (i & 1)
        cout << a[i / 2] << " " << a[m - 1 - i / 2] << " ";
      else
        cout << a[m - 1 - i / 2] << " " << a[i / 2] << " ";
    }
    cout << ENDL;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}