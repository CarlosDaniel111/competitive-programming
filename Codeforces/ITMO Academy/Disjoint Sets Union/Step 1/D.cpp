#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

struct DSU {
  vector<int> e;
  DSU(int n) : e(n, -1) {}
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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  while (m--) {
    int u, v;
    cin >> u >> v;
  }
  vector<tuple<string, int, int>> op(k);
  FOR(i, 0, k) {
    string s;
    int u, v;
    cin >> s >> u >> v;
    op[i] = {s, u, v};
  }
  DSU dsu(n + 5);
  vector<string> res;
  ROF(i, k, 0) {
    auto [s, x, y] = op[i];
    if (s[0] == 'a') {
      res.pb(dsu.get(x) == dsu.get(y) ? "YES" : "NO");
    } else {
      dsu.join(x, y);
    }
  }
  reverse(ALL(res));
  for (auto x : res) {
    cout << x << ENDL;
  }

  return 0;
}