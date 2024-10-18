#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

constexpr ll INF = 3e5;
ll dp[1005][1005][2];
ll n;
vi a, b, c;

ll solve(ll i, ll min, ll bn) {
  if (min > 780) return -INF;
  if (i == n || min > 480) {
    return 0;
  }
  ll &ans = dp[i][min][bn];
  if (ans != -1) return ans;
  ans = solve(i + 1, min, bn);
  if (bn) {
    ans = max(ans, solve(i + 1, min + a[i] * 3, bn) + c[i]);
  } else {
    ans = max(ans, solve(i + 1, min + a[i] * 3, bn) + b[i]);
  }
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  memset(dp, -1, sizeof(dp));

  cin >> n;
  a.resize(n), b.resize(n), c.resize(n);
  FOR(i, 0, n) cin >> a[i];
  FOR(i, 0, n) cin >> b[i];
  FOR(i, 0, n) cin >> c[i];

  ll ans1 = solve(0, 0, 0);
  ll ans2 = solve(0, 0, 1);
  if (ans1 == ans2) {
    cout << "EITHER" << ENDL;
  } else if (ans1 > ans2) {
    cout << "PLEASURE" << ENDL;
  } else {
    cout << "FAME" << ENDL;
  }

  return 0;
}