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
constexpr ll INF = 1e15 + 5;
constexpr ll LLINF = 1e18;

void solve() {
  ll n;
  cin >> n;
  ll mx = 0;
  ll mn = INF;
  set<ll> s;
  s.clear();
  FOR(i, 0, n) {
    ll op, x;
    cin >> op >> x;
    if (op == 2) {
      mn = min(mn, x);
    } else if (op == 1) {
      mx = max(mx, x);
    } else {
      s.insert(x);
    }
  }
  ll ans = mn - mx + 1;
  for (auto x : s) {
    if (x >= mx && x <= mn) ans--;
  }
  cout << max(ans, 0LL) << ENDL;
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