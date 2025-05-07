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
  ll n;
  cin >> n;
  vi a(n + 1, 0);
  FOR(i, 1, n + 1) {
    cin >> a[i];
  }

  vi res(n + 1, n);
  FOR(i, 1, n + 1) {
    if ((i != 1 && a[i] < a[i - 1]) || (i != n && a[i] < a[i + 1])) res[i] = 1;
  }
  ll r = 0;
  vi suma(n + 2, 0);
  FOR(i, 1, n + 1) {
    suma[i] = suma[i - 1] + a[i];
    ll pos = lower_bound(suma.begin(), suma.begin() + r, suma[i - 1] - a[i]) - suma.begin();
    if (pos)
      res[i] = min(res[i], i - pos);
    if (i > 1 && a[i] != a[i - 1])
      r = i - 1;
  }
  reverse(a.begin() + 1, a.end());
  fill(ALL(suma), 0);
  r = 0;
  FOR(i, 1, n + 1) {
    suma[i] = suma[i - 1] + a[i];
    ll pos = lower_bound(suma.begin(), suma.begin() + r, suma[i - 1] - a[i]) - suma.begin();
    if (pos)
      res[n - i + 1] = min(res[n - i + 1], i - pos);
    if (i > 1 && a[i] != a[i - 1])
      r = i - 1;
  }

  FOR(i, 1, n + 1) {
    if (res[i] == n)
      cout << -1 << " ";
    else
      cout << res[i] << " ";
  }
  cout << ENDL;
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