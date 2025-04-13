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
constexpr ll INF = 1e9;
constexpr ll LLINF = 1e18;

void solve() {
  ll n;
  cin >> n;
  vi a(n);
  vi b(n);
  vector<pi> c(n);
  FOR(i, 0, n)
  cin >> a[i];
  FOR(i, 0, n)
  cin >> b[i];
  FOR(i, 0, n) {
    c[i] = {a[i] + b[i], i};
  }
  sort(c.rbegin(), c.rend());
  ll ans = 0;
  FOR(i, 0, n) {
    if (i % 2 == 0) {
      ans += a[c[i].second] - 1;
    } else {
      ans -= b[c[i].second] - 1;
    }
  }
  cout << ans << ENDL;
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