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
  vi ans(n, 0);
  if (n % 2 == 0) {
    cout << -1 << ENDL;
    return;
  }
  for (int i = 0, cnt = 1; i < n; i += 2, cnt++) {
    ans[i] = cnt;
  }
  for (int i = 1, cnt = n; i < n; i += 2, cnt--) {
    ans[i] = cnt;
  }
  for (auto x : ans) {
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