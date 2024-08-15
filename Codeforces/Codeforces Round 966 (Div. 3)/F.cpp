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

ll n, k;
vector<pi> rect;
constexpr ll INF = 3e15;
vector<vi> dp;

ll solve(ll i, ll falta) {
  if (falta == 0) return 0;
  if (i == n) return INF;
  ll &ans = dp[i][falta];
  if (ans != -1) return ans;

  ans = INF;

  ll a = rect[i].first, b = rect[i].second;
  ll cnt = 0;
  vi c(falta + 1, INF);
  c[0] = 0;
  ll cost = 0;
  while (cnt < falta && (a > 0 || b > 0)) {
    if (a < b) swap(a, b);
    cnt++;
    cost += b;
    a--;
    c[cnt] = cost;
  }
  FOR(j, 0, falta + 1) {
    ans = min(ans, solve(i + 1, falta - j) + c[j]);
  }
  return ans;
}

void solve() {
  cin >> n >> k;
  dp.assign(n + 1, vi(k + 1, -1));
  rect.resize(n);
  FOR(i, 0, n) {
    ll a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    rect[i] = {a, b};
  }

  ll ans = solve(0, k);
  if (ans >= INF) ans = -1;
  cout << ans << ENDL;
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