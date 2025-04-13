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
  DSU derecha;
  vi top(n);
  iota(ALL(top), 0);
  derecha.init(n + 5);
  derecha.join(0, 1);
  top[0] = 1;

  FOR(i, 1, n - 1) {
    if (abs(a[i] - a[i + 1]) < abs(a[i] - a[i - 1])) {
      derecha.join(i, i + 1);
      top[derecha.get(i)] = i + 1;
    }
  }

  // izquierda
  DSU izquierda;
  vi bottom(n);
  iota(ALL(bottom), 0);
  izquierda.init(n + 5);
  izquierda.join(n - 1, n - 2);
  bottom[izquierda.get(n - 1)] = n - 2;

  for (ll i = n - 2; i; i--) {
    if (abs(a[i] - a[i + 1]) > abs(a[i] - a[i - 1])) {
      izquierda.join(i, i - 1);
      bottom[izquierda.get(i)] = i - 1;
    }
  }

  ll q;
  cin >> q;
  while (q--) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    if (x < y) {
      if (top[derecha.get(x)] >= y) {
        cout << y - x << ENDL;
      } else {
        ll ans = top[derecha.get(x)] - x;
        ans += abs(a[top[derecha.get(x)]] - a[y]);
        cout << ans << ENDL;
      }
    } else {
      if (bottom[izquierda.get(x)] <= y) {
        cout << x - y << ENDL;
      } else {
        ll ans = x - bottom[izquierda.get(x)];
        ans += abs(a[bottom[izquierda.get(x)]] - a[y]);
        cout << ans << ENDL;
      }
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