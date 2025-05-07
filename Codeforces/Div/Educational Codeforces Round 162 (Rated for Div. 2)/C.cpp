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
  vi a(n);
  FOR(i, 0, n) {
    cin >> a[i];
  }
  vi prefix(n + 1, 0);
  FOR(i, 1, n + 1) {
    prefix[i] = a[i - 1] + prefix[i - 1] - 1;
  }
  vi cnt1(n + 1, 0);
  FOR(i, 1, n + 1) {
    cnt1[i] = cnt1[i - 1] + (a[i - 1] == 1);
  }

  while (q--) {
    ll l, r;
    cin >> l >> r;
    if (l == r) {
      cout << "NO" << ENDL;
      continue;
    }
    l--;
    ll suma = prefix[r] - prefix[l];
    ll cnt = cnt1[r] - cnt1[l];
    if (suma >= cnt) {
      cout << "YES" << ENDL;
    } else {
      cout << "NO" << ENDL;
    }
  }
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