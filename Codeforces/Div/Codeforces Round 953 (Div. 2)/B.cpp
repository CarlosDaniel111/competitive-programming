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

ll sum(ll x) { return x * (x + 1) / 2; }

void solve() {
  ll n, a, b;
  cin >> n >> a >> b;
  if (a >= b) {
    cout << n * a << ENDL;
    return;
  }
  ll k = min(b - a, n);
  ll ans = sum(b) - sum(b - k);
  ans += (n - k) * a;
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}