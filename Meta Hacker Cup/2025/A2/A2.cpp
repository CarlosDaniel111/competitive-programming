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

void solve(ll t) {
  ll n;
  cin >> n;
  vector<ll> a(n + 2, 0);
  FOR(i, 1, n + 1) { cin >> a[i]; }
  auto can = [&](ll h) -> bool {
    vi valid(n + 2);
    FOR(i, 0, n + 2) valid[i] = (a[i] <= h);
    FOR(i, 1, n + 1) {
      if (valid[i - 1] && abs(a[i] - a[i - 1]) <= h) valid[i] = 1;
    }
    ROF(i, n + 1, 1)
    if (valid[i + 1] && abs(a[i] - a[i + 1]) <= h) valid[i] = 1;

    FOR(i, 1, n + 1) if (!valid[i]) return false;
    return true;
  };
  ll l = 0, r = 1e9 + 5;
  while (l < r) {
    ll mid = (l + r) / 2;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << "Case #" << t << ": " << l << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t;
  cin >> t;
  FOR(i, 1, t + 1) solve(i);

  return 0;
}