#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<vi> g(n);
  FOR(u, 1, n) {
    int p;
    cin >> p;
    p--;
    g[p].pb(u);
  }
  string s;
  cin >> s;
  s = " " + s;
  vector<vi> aut;
  auto dfs = [&](auto self, int u, int prevPhi, int phi) -> int {
    vi row(26);
    FOR(c, 0, 26) {
      if (SZ(aut) && c + 'a' != s[u])
        row[c] = aut[prevPhi][c];
      else
        row[c] = SZ(aut) + (c + 'a' == s[u]);
    }
    aut.push_back(row);
    int res = 0, sz = SZ(aut);
    if (phi && sz % (sz - phi) == 0) res = sz - phi;
    for (auto v : g[u])
      res = max(res, self(self, v, phi, aut[phi][s[v] - 'a']));
    aut.pop_back();
    return res;
  };
  int ans = 0;
  for (auto v : g[0]) {
    ans = max(ans, dfs(dfs, v, 0, 0));
  }
  cout << ans << ENDL;

  return 0;
}