#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
const int MOD = 998244353;
ll be(ll a, ll b, ll m = MOD) {
  ll res = 1;
  a %= m;
  while (b) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  vi a(n);
  ll sum = 0;
  ll mn = 0;
  FOR(i, 0, n) {
    cin >> a[i];
    sum += a[i];
    mn = min(mn, sum);
  }
  if (mn == 0) {
    cout << be(2, n) << ENDL;
    return;
  }
  int pos = 0;
  sum = 0;
  ll ans = 0;
  FOR(i, 0, n) {
    sum += a[i];
    if (sum == mn) (ans += be(2, pos + (n - i - 1))) %= MOD;
    pos += (sum >= 0);
  }
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}