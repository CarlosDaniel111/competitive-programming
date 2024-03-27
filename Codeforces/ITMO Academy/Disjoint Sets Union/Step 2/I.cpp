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
  vector<ll> e, len;
  DSU(ll n) : e(n, -1), len(n, 0) {}

  pi get(ll x) {
    if (e[x] < 0) return {x, 0};
    auto [p, l] = get(e[x]);
    e[x] = p;
    len[x] = (len[x] + l) % 2;
    return {p, len[x]};
  }
  bool join(ll a, ll b) {
    auto [px, lx] = get(a);
    auto [py, ly] = get(b);
    if (px == py) return lx != ly;

    if (e[px] > e[py]) {
      swap(px, py);
      swap(lx, ly);
    }
    e[px] += e[py];
    e[py] = px;
    len[py] = (1 + lx + ly) % 2;
    return true;
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, m, shift = 0;
  cin >> n >> m;
  DSU dsu(n + 1);
  FOR(i, 1, m + 1) {
    int op, a, b;
    cin >> op >> a >> b;
    a = (a + shift) % n, b = (b + shift) % n;
    if (op == 0) {
      dsu.join(a, b);
    } else {
      pi ax = dsu.get(a);
      pi ay = dsu.get(b);
      if (ax.second == ay.second) {
        cout << "YES" << ENDL;
        shift++;
        shift %= n;
      } else {
        cout << "NO" << ENDL;
      }
    }
  }

  return 0;
}