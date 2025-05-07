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

const int D = 1505;
struct XorBasis {
  bitset<D> basis[D], vis[D];
  int sz = 0;

  pair<bitset<D>, bitset<D>> insert(bitset<D> &k, int pos) {
    bitset<D> currVis;
    currVis.set(pos);
    for (int i = D - 1; i >= 0; i--) {
      if (!k[i]) continue;
      if (!basis[i].any()) {
        basis[i] = k;
        vis[i] = currVis;
        return {k, currVis};
      }
      k ^= basis[i];
      currVis ^= vis[i];
    }
    return {k, currVis};
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<bitset<D>> a(n);
  FOR(i, 0, n) {
    cin >> a[i];
    a[i].set(m + 1);
  }
  XorBasis xb;
  FOR(i, 0, n) {
    auto [k, currVis] = xb.insert(a[i], i);
    if (k.any()) continue;
    int cnt = 0;
    int tot = currVis.count();
    FOR(j, 0, n) {
      if (currVis[j]) {
        cout << 1 + (cnt++ >= tot / 2);
      } else {
        cout << 0;
      }
    }
    cout << ENDL;
    return 0;
  }
  cout << "*" << ENDL;

  return 0;
}