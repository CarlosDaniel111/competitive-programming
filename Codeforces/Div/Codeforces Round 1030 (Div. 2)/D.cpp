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

int LIM = 0;
vector<vector<int>> dp[2];
vector<ll> p, d;
ll n, k;

int can(ll t, ll pos, ll dir) {
  int &ans = dp[dir][t][pos];
  if (ans != -1) return ans;
  if ((t - d[pos] + k) % k == 0) {
    dir = !dir;
  }
  ans = 0;
  if (dir) {
    if (pos + 1 == n) return 1;
    ans = can((t + p[pos + 1] - p[pos]) % k, pos + 1, dir);
  } else {
    if (pos == 0) return 1;
    ans = can((t + p[pos] - p[pos - 1]) % k, pos - 1, dir);
  }
  return ans;
}

void solve() {
  cin >> n >> k;

  p.resize(n);
  d.resize(n);
  FOR(i, 0, n) cin >> p[i];
  FOR(i, 0, n) cin >> d[i];
  ll q;
  cin >> q;
  FOR(i, 0, q) {
    ll x;
    cin >> x;
    ll pos = lower_bound(ALL(p), x) - p.begin();
    dp[0].assign(k, vector<int>(n, -1));
    dp[1].assign(k, vector<int>(n, -1));
    if (pos == n) {
      cout << "YES" << ENDL;
      continue;
    }
    if (can((p[pos] - x) % k, pos, 1)) {
      cout << "YES" << ENDL;
    } else {
      cout << "NO" << ENDL;
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}