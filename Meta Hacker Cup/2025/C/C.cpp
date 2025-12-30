#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using i128 = __int128;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

void solve(ll t) {
  int n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];

  i128 ans = (i128)n * (n + 1) * (n + 2) / 6;

  map<ll, ll> bucket;
  ll p = 0;
  bucket[p]++;
  FOR(i, 0, n) {
    p = p xor a[i];
    bucket[p]++;
  }

  for (auto [_, f] : bucket) {
    if (f >= 2) ans -= (i128)f * (f - 1) * (f + 1) / 6;
  }
  ll ansprint = ans;
  cout << "Case #" << t << ": " << ansprint << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t;
  cin >> t;
  FOR(i, 1, t + 1) solve(i);

  return 0;
}