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
  vi a(n);
  vi b(m);
  FOR(i, 0, n) {
    cin >> a[i];
  }
  FOR(i, 0, m) {
    cin >> b[i];
  }

  sort(ALL(a));
  sort(ALL(b));
  ll ans = 0;
  ll leftM = 0;
  ll rightM = m - 1;
  ll leftN = 0;
  ll rightN = n - 1;
  FOR(i, 0, n) {
    ll op1 = abs(a[rightN] - b[leftM]);
    ll op2 = abs(a[leftN] - b[rightM]);
    if (op1 > op2) {
      ans += op1;
      leftM++;
      rightN--;
    } else {
      ans += op2;
      rightM--;
      leftN++;
    }
  }
  // ans += abs(a[i] - b[m - i - 1]);
  // ans += abs(a[n - i - 1] - b[i]);

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