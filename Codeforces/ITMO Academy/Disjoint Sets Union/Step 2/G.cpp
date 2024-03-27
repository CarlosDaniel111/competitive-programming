#include <bits/stdc++.h>
using namespace std;

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

using Edge = tuple<ll, ll, ll>;

struct DSU {
  vector<ll> e;
  DSU(ll n) : e(n, -1) {}
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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll V, E;
  cin >> V >> E;

  DSU dsu(V + 5);
  Edge edges[E];

  for (ll i = 0; i < E; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    edges[i] = {w, u, v};
  }
  sort(edges, edges + E);

  ll ans = 0;

  ll totalWeight = 0;
  for (ll i = 0; i < E && V > 1; i++) {
    auto [w, u, v] = edges[i];
    if (dsu.get(u) != dsu.get(v)) {
      totalWeight += w;
      ans = max(ans, w);
      V -= dsu.join(u, v);
    }
  }
  cout << ans << '\n';

  return 0;
}