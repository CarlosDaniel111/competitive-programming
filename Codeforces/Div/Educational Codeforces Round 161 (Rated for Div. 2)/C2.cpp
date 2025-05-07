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

struct DSU {
  vector<ll> e;
  void init(ll n) { e = vi(n, -1); }
  ll size(ll x) { return -e[get(x)]; }
  ll get(ll x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

  bool join(ll a, ll b) {
    a = get(a), b = get(b);
    if (a == b)
      return false;
    if (e[a] > e[b])
      swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

void solve() {
  ll n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n) {
    cin >> a[i];
  }
  // derecha
  /*vi derecha(n);
  iota(ALL(derecha), 0);
  ll j = 0;
  FOR(i, 1, n - 1) {
    if (abs(a[i] - a[i - 1]) > abs(a[i] - a[i + 1])) {
      continue;
    }
    for (; j <= i; j++) {
      derecha[j] = i;
    }
  }

  vi izquierda(n);
  iota(ALL(izquierda), 0);
  j = n - 1;
  for (ll i = n - 2; i; i--) {
    if (abs(a[i] - a[i - 1]) < abs(a[i] - a[i + 1])) {
      continue;
    }
    for (; j >= i; j--) {
      izquierda[j] = i;
    }
  }*/

  vi prefix(n + 1, 0);
  FOR(i, 0, n - 1) {
    ll sig = abs(a[i + 1] - a[i]);
    if (i == 0 || abs(a[i + 1] - a[i]) < abs(a[i - 1] - a[i])) {
      sig = 1;
    }
    prefix[i + 1] = prefix[i] + sig;
  }

  vi prefix2(n + 1, 0);
  ROF(i, n, 1) {
    ll sig = abs(a[i - 1] - a[i]);
    if (i == n - 1 || abs(a[i + 1] - a[i]) > abs(a[i - 1] - a[i])) {
      sig = 1;
    }
    prefix2[i - 1] = prefix2[i] + sig;
  }

  ll q;
  cin >> q;
  while (q--) {
    ll x, y;
    cin >> x >> y;
    x--, y--;
    if (x < y) {
      cout << prefix[y] - prefix[x] << ENDL;
    } else {
      cout << prefix2[y] - prefix2[x] << ENDL;
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