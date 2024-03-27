#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
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
constexpr ll INF = 1e9;
constexpr ll LLINF = 1e18;

void solve() {
  ll n, m;
  cin >> n >> m;
  vi a(n * m);
  FOR(i, 0, n * m) {
    cin >> a[i];
  }
  sort(ALL(a));

  ll mn = a[0];
  ll mn2 = a[1];
  ll mx = a[n * m - 1];
  ll ans = (n - 1) * (m - 1) * (mx - mn);
  if (n > m) {
    ans += (n - 1) * (mx - mn);
    ans += (m - 1) * (mx - mn2);
  } else {
    ans += (m - 1) * (mx - mn);
    ans += (n - 1) * (mx - mn2);
  }

  ll mx2 = a[n * m - 2];
  ll ans2 = (n - 1) * (m - 1) * (mx - mn);
  if (n > m) {
    ans2 += (n - 1) * (mx - mn);
    ans2 += (m - 1) * (mx2 - mn);
  } else {
    ans2 += (m - 1) * (mx - mn);
    ans2 += (n - 1) * (mx2 - mn);
  }

  cout << max(ans, ans2) << ENDL;
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