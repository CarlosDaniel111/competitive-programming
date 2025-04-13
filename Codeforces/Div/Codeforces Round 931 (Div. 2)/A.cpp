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
  vi a(n);
  FOR(i, 0, n) {
    cin >> a[i];
  }
  sort(ALL(a));
  ll ai = a[0];
  ll ak = a[1];
  ll aj = a[n - 1];
  ll al = a[n - 2];
  ll ans = abs(ai - aj) + abs(aj - ak) + abs(ak - al) + abs(al - ai);
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