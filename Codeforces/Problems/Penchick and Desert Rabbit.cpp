#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
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
  vi a(n);
  int mx = -1;
  FOR(i, 0, n) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  vi prefMax(n + 1, 0);
  vi suffMin(n + 1, 1e9 + 5);
  FOR(i, 0, n) prefMax[i + 1] = max(prefMax[i], a[i]);
  ROF(i, n, 0) suffMin[i] = min(suffMin[i + 1], a[i]);
  vi ans(n);
  ans[n - 1] = mx;
  ROF(i, n - 1, 0) {
    if (prefMax[i + 1] > suffMin[i + 1])
      ans[i] = ans[i + 1];
    else {
      ans[i] = prefMax[i + 1];
    }
  }
  for (auto x : ans) cout << x << " ";
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}