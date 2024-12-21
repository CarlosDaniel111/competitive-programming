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
  vi aa(n);
  FOR(i, 0, n) { cin >> aa[i]; }
  int yo = aa[0];
  vi a;
  FOR(i, 0, n) {
    if (aa[i] > yo) a.pb(aa[i]);
  }
  sort(ALL(a));
  n = SZ(a);
  vi b(m);
  FOR(i, 0, m) cin >> b[i];
  vi cnt(m);
  FOR(i, 0, m) {
    if (b[i] <= yo) {
      cnt[i] = 0;
    } else {
      cnt[i] = n - (lower_bound(ALL(a), b[i]) - a.begin());
    }
  }
  sort(ALL(cnt));
  FOR(k, 1, m + 1) {
    ll ans = m / k;
    for (int i = k - 1; i < m; i += k) {
      ans += cnt[i];
    }
    cout << ans << " ";
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