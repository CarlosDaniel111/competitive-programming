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
  vi a(n);
  int cnt0 = 0;
  FOR(i, 0, n) {
    cin >> a[i];
    cnt0 += (a[i] == 0);
  }
  if (cnt0 == 0) {
    cout << "YES" << ENDL;
    return;
  }
  FOR(i, 0, n - 1) {
    if (a[i] == 0 && a[i + 1] == 0) {
      cout << "YES" << ENDL;
      return;
    }
  }
  cout << "NO" << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}