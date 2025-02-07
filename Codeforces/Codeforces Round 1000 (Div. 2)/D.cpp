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
  ll n, m;
  cin >> n >> m;
  vi a(n), b(m);
  FOR(i, 0, n) cin >> a[i];
  FOR(i, 0, m) cin >> b[i];
  sort(ALL(a));
  sort(ALL(b));

  vi score0, score2;
  FOR(i, 0, n / 2) { score0.pb(a[n - i - 1] - a[i]); }
  FOR(i, 0, m / 2) { score2.pb(b[m - i - 1] - b[i]); }

  vi prefix0(SZ(score0) + 1, 0), prefix2(SZ(score2) + 1, 0);
  FOR(i, 0, SZ(score0)) { prefix0[i + 1] = prefix0[i] + score0[i]; }
  FOR(i, 0, SZ(score2)) { prefix2[i + 1] = prefix2[i] + score2[i]; }

  ll k = 1;
  vi ans;
  while (true) {
    ll l = max(0ll, 2 * k - m), r = min(k, n - k);
    if (l > r) break;
    while (l < r) {
      ll m = (l + r) / 2;
      if (score0[m] - score2[k - m - 1] > 0)
        l = m + 1;
      else
        r = m;
    }
    ans.pb(prefix0[r] + prefix2[k - r]);
    k++;
  }
  cout << SZ(ans) << ENDL;
  for (auto x : ans) cout << x << " ";
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}