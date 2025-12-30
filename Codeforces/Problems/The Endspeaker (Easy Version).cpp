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

const ll INF = 1e18;

void solve() {
  int n, m;
  cin >> n >> m;
  vi a(n), b(m);
  FOR(i, 0, n) cin >> a[i];
  FOR(i, 0, m) cin >> b[i];
  vector<vi> dp(n, vi(m, -1));
  vi pref(n + 1, 0);
  FOR(i, 0, n) pref[i + 1] = pref[i] + a[i];
  auto sol = [&](auto self, int i, int j) -> ll {
    if (i >= n) return 0;
    if (j == m) return INF;
    ll &ans = dp[i][j];
    if (ans != -1) return ans;
    ans = self(self, i, j + 1);
    int nxt = upper_bound(ALL(pref), pref[i] + b[j]) - pref.begin() - 1;
    if (nxt > i) ans = min(ans, self(self, nxt, j) + m - (j + 1));
    return ans;
  };
  ll ans = sol(sol, 0, 0);
  if (ans >= INF) ans = -1;
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}