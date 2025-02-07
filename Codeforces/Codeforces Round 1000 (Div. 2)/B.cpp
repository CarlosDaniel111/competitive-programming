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
  int n, l, r;
  cin >> n >> l >> r;
  vi der, izq;
  FOR(i, 1, n + 1) {
    ll x;
    cin >> x;
    if (i >= l) der.pb(x);
    if (i <= r) izq.pb(x);
  }
  sort(ALL(der)), sort(ALL(izq));
  ll ans1 = 0, ans2 = 0;
  FOR(i, 0, r - l + 1) {
    ans1 += der[i];
    ans2 += izq[i];
  }
  cout << min(ans1, ans2) << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}