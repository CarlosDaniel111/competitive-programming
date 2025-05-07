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

struct DSU {
  vector<int> e;
  int comp;
  void init(int n) {
    e = vi(n, -1);
    comp = n;
  }
  int size(int x) { return -e[get(x)]; }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    comp--;
    return true;
  }
};

void solve() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  vector<pi> edgesF(m1);
  FOR(i, 0, m1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    edgesF[i] = {u, v};
  }
  DSU dsu1, dsu2;
  dsu1.init(n);
  dsu2.init(n);
  FOR(i, 0, m2) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    dsu1.join(u, v);
  }
  int ans = 0;
  FOR(i, 0, m1) {
    auto [u, v] = edgesF[i];
    if (dsu1.get(u) == dsu1.get(v)) {
      dsu2.join(u, v);
    } else
      ans++;
  }
  ans += dsu2.comp - dsu1.comp;
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}