#include <bits/stdc++.h>
using namespace std;
// AC2#
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ll((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define ROF(i, a, b) for (ll i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr ll MOD = 998244353;
constexpr ll MAXN = 1e5 + 5;
constexpr ll INF = 1e9;
constexpr ll LLINF = 1e18;

void solve() {
  // cout << "---------" << ENDL;
  ll n;
  cin >> n;
  vector<bool> abierto(n, false);
  vector<pi> llervalos(n);
  FOR(i, 0, 2 * n) {
    ll x;
    cin >> x;
    x--;
    if (abierto[x]) {
      llervalos[x] = {llervalos[x].first, i};
    } else {
      llervalos[x] = {i, i};
      abierto[x] = true;
    }
  }
  sort(ALL(llervalos));
  ll ans1 = 0, ans2 = 1;
  ll mx = -1;
  FOR(i, 0, n) {
    if (llervalos[i].first > mx) {
      ans1++;
      ans2 *= 2;
      ans2 %= MOD;
      mx = llervalos[i].second;
    } else if (llervalos[i].second > mx) {
      ans2 *= 2;
      ans2 %= MOD;
      mx = llervalos[i].second;
    }
  }
  cout << ans1 << " " << ans2 % MOD << ENDL;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}