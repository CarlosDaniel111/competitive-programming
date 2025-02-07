#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, m;
  cin >> n >> m;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  sort(ALL(a));
  vi p(n + 1, 0);
  FOR(i, 0, n) { p[i + 1] = p[i] + a[i]; }
  while (m--) {
    ll q;
    cin >> q;
    ll nn = upper_bound(ALL(a), q) - a.begin();
    ll ans = (n - nn) * q;
    ans += p[nn];
    cout << ans << ENDL;
  }

  return 0;
}