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
  FOR(i, 0, n) cin >> a[i];
  bool igual = true;
  FOR(i, 1, n) {
    if (a[i] != a[0]) {
      igual = false;
      break;
    }
  }
  if (igual) {
    cout << "NO" << ENDL;
    return;
  }

  string ans = "";
  FOR(i, 0, n) ans += "B";
  FOR(i, 0, n - 1) {
    if (a[i] != a[i + 1]) {
      if (i != 0)
        ans[i - 1] = 'R';
      else
        ans[i + 2] = 'R';
      break;
    }
  }
  cout << "YES" << ENDL;
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}