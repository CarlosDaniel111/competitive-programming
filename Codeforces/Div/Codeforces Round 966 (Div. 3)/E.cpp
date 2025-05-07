#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define RALL(x) rbegin(x), rend(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  ll w;
  cin >> w;
  vi a(w);
  FOR(i, 0, w) {
    cin >> a[i];
  }
  vi veces;
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      ll i1 = max(0ll, i - k + 1);
      ll i2 = min(i, n - k);
      ll j1 = max(0ll, j - k + 1);
      ll j2 = min(j, m - k);
      veces.pb((i2 - i1 + 1) * (j2 - j1 + 1));
    }
  }
  ll ans = 0;
  sort(RALL(veces)), sort(RALL(a));
  FOR(i, 0, w)
  ans += veces[i] * a[i];
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}