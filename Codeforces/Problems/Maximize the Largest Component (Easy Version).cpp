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

struct RollbackDSU {
  vector<int> e;
  vector<pi> st;
  void init(int n) { e = vi(n, -1); }
  int size(int x) { return -e[get(x)]; }
  int get(int x) { return e[x] < 0 ? x : get(e[x]); }
  int time() { return st.size(); }
  void rollback(int t) {
    for (int i = time(); i-- > t;) e[st[i].first] = st[i].second;
    st.resize(t);
  }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    st.push_back({a, e[a]});
    st.push_back({b, e[b]});
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  FOR(i, 0, n) cin >> grid[i];
  auto getID = [&](int i, int j) -> int { return i * m + j; };
  RollbackDSU dsu;
  dsu.init(n * m);
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (grid[i][j] == '.') continue;
      if (i && grid[i - 1][j] == '#') dsu.join(getID(i, j), getID(i - 1, j));
      if (j && grid[i][j - 1] == '#') dsu.join(getID(i, j), getID(i, j - 1));
    }
  }
  int ans = 0;
  FOR(i, 0, n) {
    int ti = dsu.time();
    FOR(j, 0, m) {
      if (j) dsu.join(getID(i, j), getID(i, j - 1));
      if (i && grid[i - 1][j] == '#') dsu.join(getID(i, j), getID(i - 1, j));
      if (i < n - 1 && grid[i + 1][j] == '#')
        dsu.join(getID(i, j), getID(i + 1, j));
    }
    ans = max(ans, dsu.size(getID(i, 0)));
    dsu.rollback(ti);
  }

  FOR(j, 0, m) {
    int ti = dsu.time();
    FOR(i, 0, n) {
      if (i) dsu.join(getID(i, j), getID(i - 1, j));
      if (j && grid[i][j - 1] == '#') dsu.join(getID(i, j), getID(i, j - 1));
      if (j < m - 1 && grid[i][j + 1] == '#')
        dsu.join(getID(i, j), getID(i, j + 1));
    }
    ans = max(ans, dsu.size(getID(0, j)));
    dsu.rollback(ti);
  }

  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}