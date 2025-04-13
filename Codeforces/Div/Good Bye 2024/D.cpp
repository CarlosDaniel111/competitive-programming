#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

constexpr ll MOD = 998244353;

ll be(ll a, ll b, ll m = MOD) {
  ll res = 1;
  a %= m;
  while (b) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

void solve() {
  ll n, q;
  cin >> n >> q;
  vi a(n), b(n);
  FOR(i, 0, n) cin >> a[i];
  FOR(i, 0, n) cin >> b[i];
  vi c = a, d = b;
  sort(ALL(c)), sort(ALL(d));
  ll ans = 1;
  FOR(i, 0, n)(ans *= min(c[i], d[i])) %= MOD;
  cout << ans << " ";
  while (q--) {
    ll opc, x;
    cin >> opc >> x;
    x--;
    if (opc == 1) {
      ll j = upper_bound(ALL(c), a[x]) - c.begin() - 1;
      if (c[j] < d[j]) {
        (ans *= be(c[j], MOD - 2)) %= MOD;
        (ans *= c[j] + 1) %= MOD;
      }
      a[x]++, c[j]++;
    } else {
      ll j = upper_bound(ALL(d), b[x]) - d.begin() - 1;
      if (d[j] < c[j]) {
        (ans *= be(d[j], MOD - 2)) %= MOD;
        (ans *= d[j] + 1) %= MOD;
      }
      b[x]++, d[j]++;
    }
    cout << ans << " ";
  }
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}