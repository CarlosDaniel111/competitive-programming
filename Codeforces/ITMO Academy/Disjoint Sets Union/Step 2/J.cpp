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

  int n, m;
  cin >> n >> m;
  int ans = -1;
  DSU dsu(n);
  FOR(i, 1, m + 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (ans == -1 && !dsu.join(a, b)) {
      ans = i;
    }
  }
  cout << ans << ENDL;

  return 0;
}