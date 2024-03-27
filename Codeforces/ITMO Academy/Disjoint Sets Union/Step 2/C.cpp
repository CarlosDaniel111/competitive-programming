#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
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
  set<int> unconnected;
  void init(int n) {
    e = vi(n, -1);
    FOR(i, 0, n) {
      unconnected.insert(i);
    }
  }
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

  void unionRange(int x, int y) {
    int pos = x;
    while ((pos = *unconnected.lower_bound(pos)) < y) {
      unconnected.erase(pos);
      join(pos, pos + 1);
    }
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  DSU dsu;
  dsu.init(n + 1);
  while (q--) {
    int op, x, y;
    cin >> op >> x >> y;
    if (op == 1) {
      dsu.join(x, y);
    } else if (op == 2) {
      dsu.unionRange(x, y);
    } else {
      cout << (dsu.get(x) == dsu.get(y) ? "YES" : "NO") << ENDL;
    }
  }

  return 0;
}