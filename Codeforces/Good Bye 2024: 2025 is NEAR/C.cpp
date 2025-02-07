#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

pi solve(ll len, ll k) {
  if (len < k) return {0ll, 0ll};
  pi res = solve(len / 2, k);
  if (len % 2 == 0) {
    return {2 * res.first + res.second * (len / 2), res.second * 2};
  }
  return {2 * res.first + (res.second + 1) * ((len + 1) / 2),
          res.second * 2 + 1};
}

void solve() {
  ll n, k;
  cin >> n >> k;
  cout << solve(n, k).first << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}