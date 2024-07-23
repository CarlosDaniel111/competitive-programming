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
  FOR(i, 0, n) cin >> a[i];
  vector<vi> g(n, vi());
  vi depth(n, 0);
  FOR(i, 1, n) {
    ll p;
    cin >> p;
    p--;
    g[p].pb(i);
    depth[i] = depth[p] + 1;
  }

  vi diff(n, 0);
  FOR(i, 0, n) {
    if (!SZ(g[i])) {
      diff[i] = 3e15;
      continue;
    }
    for (auto v : g[i]) diff[i] += a[v];
    diff[i] -= a[i];
  }

  ll ans = 0;
  ROF(i, n, 0) {
    queue<ll> q;
    q.push(i);
    while (SZ(q)) {
      ll u = q.front();
      q.pop();
      for (auto v : g[u]) {
        ll delta = min(-diff[i], diff[v]);
        if (delta > 0) {
          diff[i] += delta;
          diff[v] -= delta;
          ans += delta * (depth[v] - depth[i]);
        }
        q.push(v);
      }
    }
  }
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}