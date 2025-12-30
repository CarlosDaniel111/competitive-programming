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
  vi deg(n, 0);
  FOR(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    deg[u]++, deg[v]++;
  }
  string s;
  cin >> s;
  int uno = 0, zero = 0, incog = 0, medio = 0;
  FOR(i, 1, n) {
    if (deg[i] == 1) {
      uno += s[i] == '1';
      zero += s[i] == '0';
      incog += s[i] == '?';
    } else {
      medio += s[i] == '?';
    }
  }
  if (s[0] == '0') {
    cout << uno + (incog + 1) / 2 << ENDL;
  } else if (s[0] == '1') {
    cout << zero + (incog + 1) / 2 << ENDL;
  } else {
    int plus = (uno == zero && (medio & 1));
    cout << max(uno, zero) + (incog + plus) / 2 << ENDL;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}