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
  int n, x;
  cin >> n >> x;
  x++;
  vi a(n);
  FOR(i, 0, n) {
    cin >> a[i];
  }
  int ans = -1;
  ROF(i, 31, 0) {
    vi b;
    bool open = false;
    FOR(j, 0, SZ(a)) {
      if (!open) {
        b.push_back(a[j]);
      } else {
        b.back() = b.back() xor a[j];
      }
      if (a[j] & (1 << i))
        open = !open;
    }
    if (!(x & (1 << i))) {
      if (open) {
        cout << ans << ENDL;
        return;
      }
      a = b;
    } else {
      if (!open)
        ans = max(ans, SZ(b));
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