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

void solve() {
  ll n, k;
  cin >> n >> k;
  vi a(n);
  ll total = 0;
  FOR(i, 0, n) {
    cin >> a[i];
    total += a[i];
  }
  vector<vi> dp(n + 1, vi(k + 1, -1));
  auto solve = [&](auto self, ll i, ll queda) -> ll {
    if (queda == 0) return 0;
    if (i == n) return 0;
    ll &ans = dp[i][queda];
    if (ans != -1) return ans;
    ans = self(self, i + 1, queda);
    ll sum = 0;
    FOR(j, i + 1, min(i + 1 + queda, n)) {
      sum += a[j] - a[i];
      ans = max(ans, sum + self(self, j + 1, queda - (j - i)));
    }

    ll tot = a[i];
    FOR(j, i + 1, min(i + 1 + queda, n)) {
      tot += a[j];
      ll nuevo = (j - i + 1) * a[j];
      ans = max(ans, tot - nuevo + self(self, j, queda - (j - i)));
    }
    return ans;
  };

  cout << total - solve(solve, 0, k) << ENDL;
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