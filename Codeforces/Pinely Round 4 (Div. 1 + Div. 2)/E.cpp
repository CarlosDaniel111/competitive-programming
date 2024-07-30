#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vi> g(n);
  FOR(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  vi color(n, -1);
  color[0] = 0;
  bool bipartito = true;
  auto dfs = [&](auto self, int u) -> void {
    for (auto v : g[u]) {
      if (color[v] == -1) {
        color[v] = !color[u];
        self(self, v);
      } else if (color[u] + color[v] != 1) {
        bipartito = false;
      }
    }
  };
  dfs(dfs, 0);
  if (!bipartito) {
    cout << "Alice" << endl;
    FOR(i, 0, n) {
      cout << 1 << " " << 2 << endl;
      int x, y;
      cin >> x >> y;
    }
  } else {
    cout << "Bob" << endl;
    vi c1, c2;
    FOR(i, 0, n) {
      if (color[i])
        c2.pb(i);
      else
        c1.pb(i);
    }

    FOR(i, 0, n) {
      int color1, color2;
      cin >> color1 >> color2;
      bool hay1 = (color1 == 1 || color2 == 1);
      bool hay2 = (color1 == 2 || color2 == 2);
      if (hay1 && SZ(c1)) {
        cout << c1.back() + 1 << " " << 1 << endl;
        c1.pop_back();
      } else if (hay2 && SZ(c2)) {
        cout << c2.back() + 1 << " " << 2 << endl;
        c2.pop_back();
      } else if (c1.empty()) {
        cout << c2.back() + 1 << " " << (color1 == 1 ? color2 : color1) << endl;
        c2.pop_back();
      } else {
        cout << c1.back() + 1 << " " << (color1 == 2 ? color2 : color1) << endl;
        c1.pop_back();
      }
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}