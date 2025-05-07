#include <bits/stdc++.h>
using namespace std;
// AC2#
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ll((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define ROF(i, a, b) for (ll i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr ll MOD = 1e9 + 7;
constexpr ll MAXN = 1e5 + 5;
constexpr ll INF = 1e15;
constexpr ll LLINF = 1e18;

vi a, b, c;
ll n;
ll dp[MAXN][2][2][2];

ll resolver(ll x, ll aa, ll bb, ll cc) {
  if (aa && bb && cc) return 0;
  if (x >= n) return -INF;
  ll &ans = dp[x][aa][bb][cc];
  if (ans != -1) return ans;
  ans = 0;
  ans = resolver(x + 1, aa, bb, cc);
  if (aa == 0) {
    ans = max(ans, resolver(x + 1, 1, bb, cc) + a[x]);
  }
  if (bb == 0) {
    ans = max(ans, resolver(x + 1, aa, 1, cc) + b[x]);
  }
  if (cc == 0) {
    ans = max(ans, resolver(x + 1, aa, bb, 1) + c[x]);
  }
  return ans;
}

void solve() {
  cin >> n;
  FOR(i, 0, n) {
    memset(dp[i], -1, sizeof(dp[i]));
  }
  a.assign(n, 0);
  b.assign(n, 0);
  c.assign(n, 0);
  FOR(i, 0, n)
  cin >> a[i];
  FOR(i, 0, n)
  cin >> b[i];
  FOR(i, 0, n)
  cin >> c[i];
  cout << resolver(0, 0, 0, 0) << ENDL;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}