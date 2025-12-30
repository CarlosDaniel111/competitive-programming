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

const int MOD = 1e9 + 7;

struct mint {
  int v;
  mint() : v(0) {}
  mint(ll _v) : v(int(_v % MOD)) { v += (v < 0) * MOD; }
  mint& operator+=(mint o) {
    if ((v += o.v) >= MOD) v -= MOD;
    return *this;
  }
  mint& operator-=(mint o) {
    if ((v -= o.v) < 0) v += MOD;
    return *this;
  }
  mint& operator*=(mint o) {
    v = int((ll)v * o.v % MOD);
    return *this;
  }
  friend mint be(mint a, ll p) {
    assert(p >= 0);
    return p == 0 ? 1 : be(a * a, p / 2) * (p & 1 ? a : 1);
  }
  friend mint inv(mint a) {
    assert(a.v != 0);
    return be(a, MOD - 2);
  }
  friend mint operator+(mint a, mint b) { return a += b; }
  friend mint operator-(mint a, mint b) { return a -= b; }
  friend mint operator*(mint a, mint b) { return a *= b; }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vi a(m);
  FOR(i, 0, m) cin >> a[i];
  mint medio = inv(mint(2));
  vector<mint> e(m + 1, 0);
  mint x = 0;
  ROF(i, m, 0) {
    e[i] = x;
    x = (x + a[i]) * medio;
  }
  vector<mint> ans(n);
  ans[0] = x;
  FOR(i, 0, m) { ans[a[i] - 1] += medio * e[i]; }
  for (auto x : ans) cout << x.v << ENDL;

  return 0;
}