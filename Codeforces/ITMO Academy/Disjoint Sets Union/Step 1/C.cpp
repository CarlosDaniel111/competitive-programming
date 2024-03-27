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

struct DSU {
  vector<ll> e, sum, extra;
  DSU(ll n) : e(n, -1), extra(n, 0) {
  }
  ll size(ll x) { return -e[get(x)]; }
  ll get(ll x) { return e[x] < 0 ? x : get(e[x]); }
  ll getsum(ll x) { return e[x] < 0 ? extra[x] : extra[x] + getsum(e[x]); }
  void addsum(ll x, ll w) {
    extra[get(x)] += w;
  }
  bool join(ll a, ll b) {
    a = get(a), b = get(b);
    if (a == b)
      return false;
    if (e[a] > e[b])
      swap(a, b);
    e[a] += e[b];
    extra[b] -= extra[a];
    e[b] = a;
    return true;
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  DSU dsu(n + 5);
  while (m--) {
    string s;
    cin >> s;
    if (s[0] == 'j') {
      ll x, y;
      cin >> x >> y;
      dsu.join(x, y);
    } else if (s[0] == 'a') {
      ll x, w;
      cin >> x >> w;
      dsu.addsum(x, w);
    } else {
      ll x;
      cin >> x;
      cout << dsu.getsum(x) << ENDL;
    }
  }

  return 0;
}