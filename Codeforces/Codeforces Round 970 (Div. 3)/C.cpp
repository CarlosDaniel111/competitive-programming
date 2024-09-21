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
  ll L, R;
  cin >> L >> R;
  ll len = R - L;
  ll l = 0, r = 2e9 + 5;
  while (l < r) {
    ll m = (l + r + 1) / 2;
    if (m * (m + 1) / 2 <= len)
      l = m;
    else
      r = m - 1;
  }
  cout << l + 1 << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}