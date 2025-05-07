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
  ll n, k;
  cin >> n >> k;
  map<ll, ll> mp, antimp;
  vi a(n), b(n);
  FOR(i, 0, n) { cin >> a[i]; }
  FOR(i, 0, n) cin >> b[i];
  vi todo;
  FOR(i, 0, n) {
    todo.pb(a[i]);
    todo.pb(b[i]);
  }
  sort(ALL(todo));
  FOR(i, 0, n * 2) {
    ll x = todo[i];
    if (!mp.count(x)) {
      mp[x] = SZ(mp);
      antimp[mp[x]] = x;
    }
  }

  vi compran(SZ(mp) + 5, 0);
  vi malo(SZ(mp) + 5, 0);
  FOR(i, 0, n) {
    ll x = mp[a[i]];
    malo[x]++;
  }
  FOR(i, 0, n) {
    ll x = mp[b[i]];
    compran[x]++;
  }

  vi cntCompran(SZ(mp) + 5, 0);
  vi cntMal(SZ(mp) + 5, n);
  for (ll i = SZ(mp) + 2; i >= 0; i--) {
    cntCompran[i] = cntCompran[i + 1] + compran[i];
    cntMal[i] = cntMal[i + 1] - malo[i];
  }
  ll ans = 0;
  FOR(i, 0, SZ(mp)) {
    if ((cntMal[i] - (n - cntCompran[i])) <= k) {
      ans = max(ans, cntCompran[i] * antimp[i]);
    }
    // cout << "lo vendo a " << antimp[i] << ENDL;
    // cout << cntCompran[i] << ENDL;
    // cout << cntMal[i] << ENDL;
  }
  cout << ans << ENDL;
}

// 2 - 0
// 3 - 1
// 7 - 2
// 8 - 3
// 9 - 4

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}