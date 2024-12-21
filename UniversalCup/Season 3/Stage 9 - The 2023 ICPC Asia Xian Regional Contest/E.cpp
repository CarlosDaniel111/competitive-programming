#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<vi> f(n, vi(n / 63 + 1));
  for (int i = 0; i < n; i++) {
    vi row(n / 63 + 1);
    row[i / 63] |= 1ll << (i % 63);
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      if (c == '1') {
        row[j / 63] |= 1ll << (j % 63);
      }
    }
    f[i] = row;
  }
  vi row(n / 63 + 1);
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    row = f[i];
    FOR(j, 0, n) {
      if ((f[i][j / 63] >> (j % 63)) & 1) {
        FOR(k, 0, n / 63 + 1) { row[k] |= f[j][k]; }
      }
    }
    ll go = 0;
    FOR(k, 0, n / 63 + 1) { go += __builtin_popcountll(row[k]); }
    if (go == n) {
      ans.push_back(i);
      if (SZ(ans) == 3) break;
    }
  }
  if (SZ(ans) == 3) {
    for (int k = 0; k < 3; k++) {
      cout << ans[k] + 1 << " ";
    }
    cout << '\n';
  } else {
    cout << "NOT FOUND\n";
  }

  return 0;
}