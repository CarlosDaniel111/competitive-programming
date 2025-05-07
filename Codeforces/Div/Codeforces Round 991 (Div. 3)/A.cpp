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
  int n, m;
  cin >> n >> m;
  int curr = 0;
  vi a(n);
  FOR(i, 0, n) {
    string s;
    cin >> s;
    a[i] = SZ(s);
  }
  FOR(i, 0, n) {
    curr += a[i];
    if (curr > m) {
      cout << i << ENDL;
      return;
    }
  }
  cout << n << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}