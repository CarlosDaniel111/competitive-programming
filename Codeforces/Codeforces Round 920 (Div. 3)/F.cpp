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
  ll n, q;
  cin >> n >> q;
  vi a(n + 5);
  FOR(i, 1, n + 1) {
    cin >> a[i];
  }
  ll raiz = ceil(sqrt(n));
  vector<vi> suma1(raiz + 5, vi(n + 5, 0));
  vector<vi> suma2(raiz + 5, vi(n + 5, 0));
  FOR(k, 1, raiz + 1) {
    FOR(i, 1, n + 1) {
      suma1[k][i] = (i >= k ? suma1[k][i - k] : 0) + a[i];
      suma2[k][i] = (i >= k ? suma2[k][i - k] : 0) + a[i] * (i / k);
    }
  }

  while (q--) {
    ll s, d, k;
    cin >> s >> d >> k;
    ll t = s + d * (k - 1);
    if (d <= raiz) {
      ll ans = suma2[d][t] - suma2[d][s] + a[s] * (s / d) - (suma1[d][t] - suma1[d][s] + a[s]) * (s / d - 1);
      cout << ans << " ";
      continue;
    }
    ll ans = 0, c = 1;
    while (s <= t) {
      ans += a[s] * c;
      s += d, c++;
    }
    cout << ans << " ";
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