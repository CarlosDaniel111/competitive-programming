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
  string l, r;
  cin >> l >> r;
  int n = SZ(l);
  int ans = 0, idx = -1, idx2 = -1;
  FOR(i, 0, n) {
    if (l[i] == r[i]) {
      continue;
    }
    if (r[i] - l[i] >= 2) {
      cout << (n * 2) - ((n - i) * 2) << ENDL;
      return;
    }
    idx = i;
    idx2 = i;
    break;
  }
  if (idx == -1) {
    cout << n * 2 << ENDL;
    return;
  }

  idx++;
  ans = 1;
  while (idx < n && l[idx] == '9' && r[idx] == '0') {
    ans++;
    idx++;
  }
  cout << 2 * n - (((n - idx) * 2) + ans) << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}