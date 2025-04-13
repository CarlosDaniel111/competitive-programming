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

int cnt = 0;

ll solve(vi &a) {
  if (SZ(a) == 1) return a[0];
  ll ans1 = accumulate(ALL(a), 0ll);

  vi a1(SZ(a) - 1);
  FOR(i, 1, SZ(a)) { a1[i - 1] = a[i] - a[i - 1]; }

  reverse(ALL(a));
  vi a2(SZ(a) - 1);
  FOR(i, 1, SZ(a)) { a2[i - 1] = a[i] - a[i - 1]; }

  if (a[0] > a.back()) {
    return max(ans1, solve(a1));
  }

  else {
    return max(ans1, solve(a2));
  }
}

void solve() {
  ll n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n) { cin >> a[i]; }
  cout << solve(a) << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}