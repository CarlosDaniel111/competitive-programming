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
  vi a(n);
  FOR(i, 0, n) {
    cin >> a[i];
  }

  sort(ALL(a));
  ll ans = 0;
  for (ll i = n - 1; i >= 1; i -= 2) {
    ll sube = min(k, a[i] - a[i - 1]);
    k -= sube;
    ans += a[i] - (a[i - 1] + sube);
  }
  if (n % 2) ans += a[0];
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