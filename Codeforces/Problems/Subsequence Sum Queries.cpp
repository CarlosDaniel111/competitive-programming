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

constexpr ll MAX = 2e5 + 5, MOD = 1e9 + 7;

ll n, m, q;
vi a, ans;
vector<pi> queries;
ll dp[MAX][25];

void solve(ll l, ll r, vi &id) {
  if (!SZ(id)) return;
  if (l == r) {
    for (auto i : id) ans[i] = (a[i] == 0) + 1;
    return;
  }
  ll mid = (l + r) / 2;
  FOR(i, 0, m) dp[mid][i] = 0;
  dp[mid][0]++;
  dp[mid][a[mid]]++;
  for (ll i = mid - 1; i >= l; i--) {
    FOR(j, 0, m) {
      dp[i][j] = dp[i + 1][j];
      ll ant = (j - a[i] + m) % m;
      (dp[i][j] += dp[i + 1][ant]) %= MOD;
    }
  }

  FOR(i, 0, m) dp[mid + 1][i] = 0;
  dp[mid + 1][0]++;
  dp[mid + 1][a[mid + 1]]++;
  for (ll i = mid + 2; i <= r; i++) {
    FOR(j, 0, m) {
      dp[i][j] = dp[i - 1][j];
      ll ant = (j - a[i] + m) % m;
      (dp[i][j] += dp[i - 1][ant]) %= MOD;
    }
  }

  vi idL, idR;
  for (auto i : id) {
    ll ql = queries[i].first, qr = queries[i].second;
    if (qr < mid) {
      idL.pb(i);
    } else if (ql > mid + 1) {
      idR.pb(i);
    } else {
      if (qr == mid)
        ans[i] = dp[ql][0];
      else if (ql == mid + 1)
        ans[i] = dp[qr][0];
      else {
        FOR(j, 0, m) {
          (ans[i] += dp[ql][j] * dp[qr][(m - j) % m] % MOD) %= MOD;
        }
      }
    }
  }
  solve(l, mid, idL);
  solve(mid + 1, r, idR);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m;
  a.resize(n);
  FOR(i, 0, n) {
    cin >> a[i];
    a[i] %= m;
  }
  cin >> q;
  queries.resize(q);
  FOR(i, 0, q) {
    cin >> queries[i].first >> queries[i].second;
    queries[i].first--, queries[i].second--;
  }
  vi id(q);
  ans.assign(q, 0);
  iota(ALL(id), 0);
  solve(0, n - 1, id);
  for (auto x : ans) {
    cout << x % MOD << ENDL;
  }

  return 0;
}