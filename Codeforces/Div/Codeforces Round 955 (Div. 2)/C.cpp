#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

vi a, pref, dp;
int n, l, r;

ll solve(int i) {
  if (i == n) return 0;
  ll &ans = dp[i];
  if (ans != -1) return ans;
  ans = solve(i + 1);
  int d = lower_bound(ALL(pref), l + pref[i]) - pref.begin();
  if (d == n + 1) return ans;
  ll rango = pref[d] - pref[i];
  if (rango >= l && rango <= r)
    ans = max(ans, 1ll + solve(d));
  return ans;
}

void solve() {
  cin >> n >> l >> r;
  a.resize(n);
  FOR(i, 0, n)
  cin >> a[i];
  pref.assign(n + 1, 0);
  FOR(i, 1, n + 1)
  pref[i] = pref[i - 1] + a[i - 1];
  dp.assign(n + 5, -1);
  cout << solve(0) << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}