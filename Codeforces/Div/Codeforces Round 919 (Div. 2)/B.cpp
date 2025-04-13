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
  ll n, k, x;
  cin >> n >> k >> x;
  vi a(n);
  ll suma = 0;
  FOR(i, 0, n) {
    cin >> a[i];
    suma += a[i];
  }
  sort(a.rbegin(), a.rend());
  for (ll i = 0; i < n && i < x; i++) {
    suma -= a[i] * 2;
  }
  ll j = x;
  ll ans = suma;
  for (ll i = 0; i < k; i++, j++) {
    suma += a[i];
    if (j < n)
      suma -= a[j] * 2;
    ans = max(ans, suma);
  }
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