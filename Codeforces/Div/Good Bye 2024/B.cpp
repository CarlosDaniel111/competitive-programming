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
  vi l(n), r(n);
  vi cnt(2 * n + 1);
  FOR(i, 0, n) {
    cin >> l[i] >> r[i];
    if (l[i] == r[i]) {
      cnt[l[i]]++;
    }
  }
  vi pref(2 * n + 2);
  FOR(i, 0, 2 * n + 1) { pref[i + 1] = pref[i] + (cnt[i] >= 1); }
  FOR(i, 0, n) {
    if (l[i] == r[i]) {
      cout << (cnt[l[i]] <= 1);
    } else {
      cout << ((pref[r[i] + 1] - pref[l[i]]) < (r[i] - l[i] + 1));
    }
  }
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}