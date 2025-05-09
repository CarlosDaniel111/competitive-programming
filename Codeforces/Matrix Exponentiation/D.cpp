#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

constexpr ll MOD = 1e9 + 7;
template <typename T>
struct Matrix {
  using VVT = vector<vector<T>>;

  VVT M;
  int n;

  Matrix(VVT aux) : n(SZ(aux)), M(aux) {}

  Matrix operator*(Matrix& other) const {
    assert(SZ(M[0]) == SZ(other.M));
    int k = SZ(other.M[0]);
    VVT C(n, vector<T>(k, 0));
    FOR(i, 0, SZ(M))
    FOR(j, 0, k)
    FOR(l, 0, SZ(M[0]))
    C[i][j] = (C[i][j] + M[i][l] * other.M[l][j] % MOD) % MOD;
    return Matrix(C);
  }

  Matrix operator^(ll p) const {
    assert(p >= 0);
    Matrix ret(VVT(n, vector<T>(n))), B(*this);
    FOR(i, 0, n) { ret.M[i][i] = 1; }
    while (p) {
      if (p & 1) ret = ret * B;
      p >>= 1;
      B = B * B;
    }
    return ret;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, m, k;
  cin >> n >> m >> k;
  vector<vi> g(n, vi(n));
  FOR(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u][v] = 1;
  }

  Matrix<ll> mat(g);
  mat = mat ^ k;
  ll ans = 0;
  FOR(i, 0, n) {
    FOR(j, 0, n) {
      ans += mat.M[i][j];
      ans %= MOD;
    }
  }
  cout << ans << ENDL;

  return 0;
}