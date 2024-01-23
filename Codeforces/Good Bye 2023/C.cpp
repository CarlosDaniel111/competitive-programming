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

constexpr ll MOD = 1e9 + 7;
constexpr ll MAXN = 1e5 + 5;
constexpr ll INF = 1e9;
constexpr ll LLINF = 1e18;

void solve() {
  ll n;
  cin >> n;
  ll ans = 0, impares = 0;
  FOR(i, 0, n) {
    ll x;
    cin >> x;
    impares += (x % 2 == 1);
    // cout << impares << " ";
    if (i == 0) {
      cout << x << " ";
      ans += x;
      continue;
    }
    if (i == 1) {
      cout << ((ans + x) / 2) * 2 << " ";
      ans += x;
      if (impares == 2) {
        // impares -= 2;
      }
      continue;
    }
    if (i == 2) {
      ans += x;
      if (impares == 3 || impares == 1) {
        // impares -= 2;
        cout << ans - 1 << " ";
      } else
        cout << ans << " ";
      continue;
    }

    ans += x;
    ll ans2 = ans;
    ans2 = ans - (impares / 3);
    if (impares % 3 == 1) {
      ans2--;
    }

    cout << ans2 << " ";
  }
  cout << ENDL;
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