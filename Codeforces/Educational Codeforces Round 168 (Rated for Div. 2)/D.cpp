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

void solve() {
  ll n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n)
  cin >> a[i];
  vector<vi> g(n);
  FOR(i, 1, n) {
    ll p;
    cin >> p;
    p--;
    g[p].pb(i);
  }

  auto dfs = [&](auto self, ll u) -> ll {
    ll mn = 1e15 + 5;
    for (auto v : g[u]) {
      mn = min(mn, self(self, v));
    }
    if (mn == 1e15 + 5) return a[u];
    if (mn <= a[u]) return mn;
    return (mn + a[u]) / 2;
  };
  ll mn = 1e15 + 5;
  for (auto v : g[0]) {
    mn = min(mn, dfs(dfs, v));
  }

  if (mn == 1e15 + 5) {
    cout << a[0] << ENDL;
    return;
  }

  cout << a[0] + mn << ENDL;
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