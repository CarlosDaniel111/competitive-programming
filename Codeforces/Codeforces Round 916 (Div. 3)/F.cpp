#include <bits/stdc++.h>
using namespace std;
// AC2#
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

vector<vi> tree;
vi depth;

void dfs(ll u, ll padre = -1, ll d = 0) {
  depth[u] = d;
  for (auto &hijo : tree[u])
    if (hijo != padre)
      dfs(hijo, u, d + 1);
}

void solve() {
  ll n;
  cin >> n;
  tree.assign(n, vi());
  depth.assign(n, 0);
  FOR(i, 1, n) {
    ll x;
    cin >> x;
    x--;
    tree[x].pb(i);
    tree[i].pb(x);
  }
  dfs(0);
  vi cont(n, 0);
  ll mx_depth = 0;
  FOR(i, 0, n) {
    cont[depth[i]]++;
    mx_depth = max(mx_depth, depth[i]);
  }

  ll ans = 0;
  ll padre = mx_depth - 1;
  ROF(i, mx_depth + 1, 0) {
    ans += cont[i] / 2;
    cont[i] %= 2;
    if (cont[i] == 1) {
      while (padre >= 0) {
        if (cont[padre] > 1) break;
        padre--;
      }
      if (padre != -1) {
        ans++;
        cont[padre]--;
      }
    }
  }
  cout << ans << ENDL;

  /*FOR(i, 0, mx_depth + 1) {
    cout << cont[i] << " ";
  }
  cout << ENDL;*/
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}