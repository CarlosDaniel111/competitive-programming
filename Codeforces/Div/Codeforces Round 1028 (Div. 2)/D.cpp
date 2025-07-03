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
  int n, q;
  cin >> n >> q;
  vi a(n), b(n);
  FOR(i, 0, n) {
    cin >> b[i];
    a[i] = b[i];
  }
  vi x(q), y(q), z(q);
  FOR(i, 0, q) {
    cin >> x[i] >> y[i] >> z[i];
    x[i]--, y[i]--, z[i]--;
  }
  ROF(i, q, 0) {
    int aux = a[z[i]];
    a[z[i]] = 0;
    a[x[i]] = max(a[x[i]], aux);
    a[y[i]] = max(a[y[i]], aux);
  }
  vi aa(a.begin(), a.end());
  FOR(i, 0, q) { aa[z[i]] = min(aa[x[i]], aa[y[i]]); }
  FOR(i, 0, n) {
    if (aa[i] != b[i]) {
      cout << -1 << ENDL;
      return;
    }
  }
  FOR(i, 0, n) { cout << a[i] << " "; }
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}