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

void solve() {
  ll n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << n << ENDL;
    return;
  }
  ll ans = 0;
  while (n) {
    ll curr = 1;
    while (true) {
      if (curr * k > n) {
        ans += (n / curr);
        n %= curr;
        break;
      }
      curr *= k;
    }
  }
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