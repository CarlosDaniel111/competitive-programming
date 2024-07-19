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
  void init(int n) { e = vi(n, -1); }
  int size(int x) { return -e[get(x)]; }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b)
      return false;
    if (e[a] > e[b])
      swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

void solve() {
  int n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n) {
    cin >> a[i];
  }
  DSU dsu;
  dsu.init(n);
  vector<pi> ans;
  ROF(x, n, 1) {
    vi vis(n, -1);
    FOR(u, 0, n) {
      int v = vis[a[u] % x];
      if (v != -1 && dsu.get(u) != dsu.get(v)) {
        ans.pb({u, v});
        dsu.join(u, v);
        break;
      }
      vis[a[u] % x] = u;
    }
  }

  reverse(ALL(ans));
  cout << "YES" << ENDL;
  for (auto [u, v] : ans) {
    cout << u + 1 << " " << v + 1 << ENDL;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}