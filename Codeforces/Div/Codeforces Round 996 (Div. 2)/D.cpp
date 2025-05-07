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

void solve() {
  ll n, k, l;
  cin >> n >> k >> l;
  k *= 2, l *= 2;
  vi a(n);
  FOR(i, 0, n) {
    cin >> a[i];
    a[i] *= 2;
  }

  ll ans = a[0], pos = k;

  FOR(i, 1, n) {
    if (pos >= l) break;
    ll left = a[i] - ans, right = a[i] + ans;
    if (left <= pos && pos <= right)
      pos += k;
    else if (pos < left) {
      ans += (left - pos) / 2;
      pos += k + (left - pos) / 2;
    } else {
      pos = max(pos, right + k);
    }
  }
  ans += max(0ll, l - pos);
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}