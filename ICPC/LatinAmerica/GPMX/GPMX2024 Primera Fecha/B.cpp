#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

constexpr ll MOD = 1e9 + 7;

template <typename T>
struct Matrix {
  using VVT = vector<vector<T>>;

  VVT M;
  ll n, m;

  Matrix(VVT aux) : M(aux), n(M.size()), m(M[0].size()) {}

  Matrix operator*(Matrix& other) const {
    ll k = other.M[0].size();
    VVT C(n, vector<T>(k, 0));
    FOR(i, 0, n)
    FOR(j, 0, k)
    FOR(l, 0, m)
    C[i][j] = (C[i][j] + M[i][l] * other.M[l][j] % MOD) % MOD;
    return Matrix(C);
  }

  Matrix operator^(ll p) const {
    assert(p >= 0);
    Matrix ret(VVT(n, vector<T>(n))), B(*this);
    FOR(i, 0, n)
    ret.M[i][i] = 1;

    while (p) {
      if (p & 1)
        ret = ret * B;
      p >>= 1;
      B = B * B;
    }
    return ret;
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

    vector<vector<ll>> mat(20, vector<ll>(20, 0));

  mat[0][5] = 3;
  mat[0][9] = 3;
  mat[0][13] = 3;
  mat[0][17] = 3;
  FOR(i, 1, 20) {
    FOR(j, 0, 20) {
      if (i - 1 == j) mat[i][j] = 1;
    }
  }

  vector<vector<ll>> a(20, vector<ll>(1, 0));
  a[1][0] = 30;
  a[3][0] = 18;
  a[5][0] = 3;
  a[7][0] = 9;
  a[9][0] = 3;
  a[13][0] = 3;
  a[19][0] = 1;

  Matrix<ll> M(mat);
  Matrix<ll> A(a);

  ll t;
  cin >> t;
  while (t--) {
    ll x;
    cin >> x;
    if (x < 20) {
      ll ans = 0;
      FOR(i, 0, x + 1) {
        ans += a[19 - i][0];
      }
      cout << ans % MOD << ENDL;
      continue;
    }
    Matrix<ll> Mpow = M ^ (x - 19);  // -> 38
    Matrix<ll> aux = Mpow * A;
    ll ans = 0;
    FOR(i, 0, 20) {
      ans += aux.M[i][0];
      ans %= MOD;
    }
    cout << ans % MOD << ENDL;
  }

  return 0;
}