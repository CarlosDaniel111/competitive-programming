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
  int n, m, k;
  cin >> n >> m >> k;
  vi a(m);
  FOR(i, 0, m) cin >> a[i];
  vi b(k);
  FOR(i, 0, k) cin >> b[i];
  if (n == k) {
    FOR(i, 0, m) cout << 1;
    cout << ENDL;
    return;
  }
  if (n != k + 1) {
    FOR(i, 0, m) cout << 0;
    cout << ENDL;
    return;
  }
  vector<bool> nose(n + 1, 1);
  FOR(i, 0, k) { nose[b[i]] = 0; }
  FOR(i, 0, m) {
    if (nose[a[i]]) {
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << ENDL;
  return;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}