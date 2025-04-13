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
  vector<vi> a(3, vi(n));
  FOR(i, 0, 3) {
    FOR(j, 0, n) { cin >> a[i][j]; }
  }
  vector<vi> prefix(3, vi(n + 1, 0));
  FOR(i, 0, 3) {
    FOR(j, 1, n + 1) { prefix[i][j] = prefix[i][j - 1] + a[i][j - 1]; }
  }

  ll buscar = ceil(prefix[0][n] / 3.0);

  vi perm = {0, 1, 2};
  vector<pair<ll, ll>> ans(3);

  auto can = [&]() -> bool {
    ll curr = 0;
    FOR(i, 0, 3) {
      ans[perm[i]].first = curr;
      curr = lower_bound(prefix[perm[i]].begin() + curr, prefix[perm[i]].end(),
                         buscar + prefix[perm[i]][curr]) -
             prefix[perm[i]].begin();
      ans[perm[i]].second = curr;
      if (i == 2) ans[perm[i]].second = n;
    }
    if (curr == n + 1) return false;
    return true;
  };

  do {
    // cout << perm[0] << " " << perm[1] << " " << perm[2] << ENDL;
    if (can()) {
      FOR(i, 0, 3) cout << ans[i].first + 1 << " " << ans[i].second << " ";
      cout << ENDL;
      return;
    }
  } while (next_permutation(ALL(perm)));
  cout << "-1" << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}