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
  int n, s;
  cin >> n >> s;
  int mn = 1e5, mx = 0;
  FOR(i, 0, n) {
    int x;
    cin >> x;
    mn = min(mn, x);
    mx = max(mx, x);
  }
  cout << mx - mn + max(0, min(abs(s - mn), abs(mx - s))) << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}