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
  int n, x, y;
  cin >> n >> x >> y;
  if (n % 2 == 0 && x % 2 != y % 2) {
    FOR(i, 0, n) { cout << (i & 1 ? '1' : '0') << " "; }
    cout << ENDL;
    return;
  }

  if (n % 2 == 0 && x % 2 == y % 2) {
    vi ans(n);
    x--, y--;
    FOR(i, 0, n) ans[i] = i % 2;
    ans[x] = 2;
    for (auto aa : ans) cout << aa << " ";
    cout << ENDL;
    return;
  }

  x--, y--;
  FOR(i, 0, x) { cout << (i & 1 ? '1' : '0') << " "; }
  cout << "2 ";
  FOR(i, x + 1, n) { cout << (i & 1 ? '0' : '1') << " "; }
  cout << ENDL;
  return;
}

// 0 2 1 2

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}