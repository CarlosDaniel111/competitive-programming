#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int q;
  cin >> q;
  while (q--) {
    ll n, t;
    cin >> n >> t;
    t--;
    ll ans = 1 + (n >= t);
    if (t == 0) {
      cout << n << ENDL;
      continue;
    }
    for (ll i = 2; i * i <= t && i <= n; i++) {
      if (t % i == 0) {
        ans += 1 + (t / i <= n && t / i != i);
      }
    }
    cout << ans << ENDL;
  }

  return 0;
}