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
  ll cntl = 0, cntr = 0;
  vi a;
  FOR(i, 0, n) {
    ll x;
    cin >> x;
    if (x == -1) {
      cntl++;
    } else if (x == -2) {
      cntr++;
    } else {
      a.pb(x);
    }
  }

  if (SZ(a) == 0) {
    cout << min(max(cntl, cntr), m) << ENDL;
    return;
  }

  sort(ALL(a));
  a.resize(unique(ALL(a)) - a.begin());

  auto f = [&](ll x) {
    ll ans = 1;
    ll cl = cntl;
    ll cr = cntr;
    ll mid = a[x];
    for (ll i = mid - 1; i >= 1; i--) {
      if (binary_search(ALL(a), i)) {
        // cout << i << ENDL;
        ans++;
        continue;
      }
      if (cl) {
        ans++;
        cl--;
      }
    }

    for (ll i = mid + 1; i <= m; i++) {
      if (binary_search(ALL(a), i)) {
        // cout << i << ENDL;
        ans++;
        continue;
      }
      if (cr) {
        ans++;
        cr--;
      }
    }
    return ans;
  };

  ll l = 0,
     r = SZ(a) - 1;
  while (r - l > 10) {
    ll m1 = l + (r - l) / 3;
    ll m2 = r - (r - l) / 3;
    ll f1 = f(m1);
    ll f2 = f(m2);
    if (f1 < f2)  // Maximo de f(x)
      l = m1;
    else
      r = m2;
  }
  ll opc1 = min(m, SZ(a) + cntl);
  ll opc2 = min(m, SZ(a) + cntr);
  ll opc4 = 0;
  FOR(i, l, r + 1) {
    opc4 = max(opc4, f(i));
  }
  cout << max({opc1, opc2, opc4}) << ENDL;
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