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
  sort(ALL(a));
  int par = -1;
  ROF(i, n - 1, 0) {
    if (a[i] == a[i + 1]) {
      par = a[i];
      a.erase(a.begin() + i);
      a.erase(a.begin() + i);
      break;
    }
  }
  if (par == -1) {
    cout << -1 << ENDL;
    return;
  }
  FOR(i, 0, SZ(a) - 1) {
    if (abs(a[i] - a[i + 1]) < par * 2) {
      cout << a[i] << " " << a[i + 1] << " " << par << " " << par << ENDL;
      return;
    }
  }
  cout << -1 << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}