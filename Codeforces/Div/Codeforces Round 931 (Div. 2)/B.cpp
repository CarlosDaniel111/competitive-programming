#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
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

constexpr ll MOD = 1e9 + 7;
constexpr ll MAXN = 1e5 + 5;
constexpr ll INF = 1e9;
constexpr ll LLINF = 1e18;

void solve() {
  ll n;
  cin >> n;
  vi num = {15, 10, 6, 3};
  // ll ans = 1e10;
  if (n == 23) {
    cout << 3 << ENDL;
    return;
  }
  if (n == 12) {
    cout << 2 << ENDL;
    return;
  }
  if (n == 20) {
    cout << 2 << ENDL;
    return;
  }

  ll cnt = n / 15;
  ll ans = 0;
  if (cnt > 1) {
    n -= (15 * (cnt - 1));
    ans += cnt - 1;
  }
  // cout << n << ENDL;

  if (n == 23) {
    cout << ans + 3 << ENDL;
    return;
  }
  if (n == 27) {
    cout << ans + 3 << ENDL;
    return;
  }
  if (n == 20) {
    cout << ans + 2 << ENDL;
    return;
  }
  FOR(i, 0, 4) {
    ans += n / num[i];
    n = n % num[i];
  }
  ans += n;
  /*do {
    ll n2 = n;
    ll curr = 0;
    FOR(i, 0, 4) {
      curr += n2 / num[i];
      n2 = n2 % num[i];
    }
    curr += n2;
    ans = min(ans, curr);
  } while (next_permutation(ALL(num)));*/
  cout << ans << ENDL;
}

// 23,12,20

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}