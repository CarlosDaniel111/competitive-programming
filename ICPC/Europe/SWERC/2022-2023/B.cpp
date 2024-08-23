#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;

constexpr ll INF = 1e18;
vector<vector<ll>> dp;
vector<ll> x;
ll n, h;

ll diagonal(int l, int r) {
  return (x[r] - x[l] + 1LL) / 2LL;
}

ll solve(int l, int r) {
  if (r - l <= 1)
    return 0;
  ll &ans = dp[l][r];
  if (ans != INF)
    return ans;
  for (int k = l; k < r; k++) {
    ll d1 = diagonal(l, k), left = solve(l, k) + min(h, d1) - (d1 <= h);
    if (k == l)
      left = 0;
    ll d2 = diagonal(k + 1, r), right = solve(k + 1, r) + min(h, d2) - (d2 <= h);
    if (k == r - 1)
      right = 0;
    ans = min(ans, left + right);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> n >> h;
  x.resize(n);
  FOR(i, 0, n)
  cin >> x[i];
  if (n == 1) {
    cout << h << ENDL;
    return 0;
  }
  dp.assign(n, vector<ll>(n, INF));
  ll d = diagonal(0, n - 1), ans = solve(0, n - 1) + 2LL * min(d, h) - (d <= h) + max(0LL, h - d);
  cout << ans << ENDL;
}