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
  x--, y--;
  vi ans(n, 0);
  FOR(i, y, x + 1) { ans[i] = 1; }
  bool menos = true;
  FOR(i, x + 1, n) {
    if (menos)
      ans[i] = -1;
    else
      ans[i] = 1;
    menos = !menos;
  }
  menos = 1;
  ROF(i, y, 0) {
    if (menos)
      ans[i] = -1;
    else
      ans[i] = 1;
    menos = !menos;
  }
  for (auto x : ans) cout << x << " ";
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