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
  ll n, l;
  cin >> n >> l >> l;
  vi a(n * 2 + 2, 0);
  FOR(i, 1, n + 1) cin >> a[i];
  for (ll i = 1; i <= (n + 1) / 2; i++) {
    a[n + 1] ^= a[i];
  }
  FOR(i, n + 2, 2 * n + 2) {
    a[i] = a[i - 1];
    if (i % 2 == 0) a[i] ^= a[i / 2];
  }
  ll allxor = 0;
  FOR(i, 1, n + 1) allxor ^= a[i];
  auto solve = [&](auto self, ll curr) -> ll {
    if (curr <= 2 * n + 1) return a[curr];
    ll res = allxor;
    if (n % 2 == 0) res ^= a[n + 1];
    if ((curr / 2) & 1) return res;
    return res ^ self(self, curr / 2);
  };
  cout << solve(solve, l) << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}