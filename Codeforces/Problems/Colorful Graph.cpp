#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  map<int, set<int>> mapa;
  vi c(n);
  FOR(i, 0, n) {
    cin >> c[i];
    mapa[c[i]] = set<int>();
  }

  while (m--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (c[u] == c[v]) continue;
    mapa[c[u]].insert(c[v]);
    mapa[c[v]].insert(c[u]);
  }
  int mx = -1, ans = 0;
  for (auto x : mapa) {
    if (SZ(x.second) > mx) {
      mx = SZ(x.second);
      ans = x.first;
    }
  }
  cout << ans << ENDL;

  return 0;
}