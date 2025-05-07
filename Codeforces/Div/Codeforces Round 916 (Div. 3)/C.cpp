#include <bits/stdc++.h>
using namespace std;
// AC2#
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

void solve() {
  ll n, k;
  cin >> n >> k;
  vi a(n);
  vi b(n);
  FOR(i, 0, n)
  cin >> a[i];
  FOR(i, 0, n)
  cin >> b[i];
  ll ans = 0;
  ll mx = 0;
  ll sum = 0;
  FOR(i, 0, min(n, k)) {
    ll prueba = 0;
    sum += a[i];
    prueba += sum;
    mx = max(mx, b[i]);
    prueba += (mx * (k - (i + 1)));
    ans = max(ans, prueba);
  }
  cout << ans << ENDL;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}