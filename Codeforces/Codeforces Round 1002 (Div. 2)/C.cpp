#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

void solve() {
  ll n;
  cin >> n;

  if (n == 1) {
    int x;
    cin >> x;
    cout << 1 << ENDL;
    return;
  }

  vi cnt1(n, 0);
  FOR(i, 0, n) {
    vi a(n);
    FOR(j, 0, n) cin >> a[j];
    ll j = n - 1;
    while (j >= 0 && a[j] == 1) cnt1[i]++, j--;
  }

  // 0 1
  multiset<ll> mst;
  for (auto x : cnt1) mst.insert(x);
  FOR(MEX, 0, n + 1) {
    // for (auto x : mst) cout << x << " ";
    // cout << ENDL;
    if (mst.lower_bound(MEX) == mst.end()) {
      cout << MEX << ENDL;
      return;
    }
    mst.erase(mst.lower_bound(MEX));
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}