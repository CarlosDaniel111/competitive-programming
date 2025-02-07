#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;
  vector<vi> g(n, vi(n));
  FOR(i, 0, n) {
    FOR(j, 0, n) { cin >> g[i][j]; }
  }
  vi a(n);
  FOR(i, 0, n) {
    cin >> a[i];
    a[i]--;
  }
  reverse(ALL(a));
  vi ans(n);
  FOR(k, 0, n) {
    FOR(u, 0, n) {
      FOR(v, 0, n) {
        g[a[u]][a[v]] = min(g[a[u]][a[v]], g[a[u]][a[k]] + g[a[k]][a[v]]);
      }
    }
    ll res = 0;
    FOR(u, 0, k + 1) {
      FOR(v, 0, k + 1) { res += g[a[u]][a[v]]; }
    }
    ans[n - k - 1] = res;
  }
  for (auto x : ans) cout << x << " ";
  cout << ENDL;

  return 0;
}