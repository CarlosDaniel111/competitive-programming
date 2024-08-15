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

constexpr ll MAX = 2e5 + 5;
vi need, pref;

void solve() {
  ll l, r;
  cin >> l >> r;
  ll ans = need[l];
  ans += (pref[r + 1] - pref[l]);
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  need.assign(MAX, 0);
  pref.assign(MAX + 1, 0);
  FOR(i, 1, MAX) {
    ll x = i;
    while (x > 0) {
      need[i]++;
      x /= 3;
    }
    pref[i + 1] = pref[i] + need[i];
  }

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}