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

constexpr ll INF = 1e8;

string a, b, c;
vector<vi> dp;

ll solve(ll pos1, ll pos2) {
  if (pos1 > SZ(a)) return INF;
  if (pos2 > SZ(b)) return INF;
  if (pos1 == SZ(a) && pos2 == SZ(b)) return 0;
  ll &ans = dp[pos1][pos2];
  if (ans != -1) return ans;
  ans = INF;
  if (pos1 < SZ(a)) {
    ans = min(ans, solve(pos1 + 1, pos2) + (c[pos2 + pos1] != a[pos1]));
  }
  if (pos2 < SZ(b)) {
    ans = min(ans, solve(pos1, pos2 + 1) + (c[pos2 + pos1] != b[pos2]));
  }
  return ans;
}

void solve() {
  cin >> a >> b >> c;
  dp.assign(SZ(a) + 5, vi(SZ(b) + 5, -1));
  cout << solve(0, 0) << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}