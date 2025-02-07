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
    C[i][j] = (C[i][j] + M[i][l] * other.M[l][j]);
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

  int k;
  cin >> k;
  k++;
  vector<vector<unsigned int>> m(65, vector<unsigned int>(65, 0));

  auto isValid = [](int x, int y) -> bool {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
  };
  FOR(i, 0, 8) {
    FOR(j, 0, 8) {
      for (int dr : {-2, -1, 1, 2}) {
        for (int dc : {-2, -1, 1, 2}) {
          if (abs(dr) == abs(dc)) continue;
          int ni = i + dr, nj = j + dc;
          if (isValid(ni, nj)) {
            m[8 * i + j][8 * ni + nj] = 1;
          }
        }
      }
    }
  }
  FOR(i, 0, 65) { m[i][64] = 1; }
  Matrix<unsigned int> mat(m);
  mat = mat ^ k;
  cout << mat.M[0][64] << ENDL;

  return 0;
}