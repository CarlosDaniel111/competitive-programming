#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

typedef double T;  // long double, Rational, double + mod<P>...
typedef vector<T> vd;
typedef vector<vd> vvd;

const T eps = 1e-8, inf = 1 / .0;
#define MP make_pair
#define ltj(X) \
  if (s == -1 || MP(X[j], N[j]) < MP(X[s], N[s])) s = j

struct LPSolver {
  int m, n;
  vi N, B;
  vvd D;

  LPSolver(const vvd& A, const vd& b, const vd& c)
      : m(SZ(b)), n(SZ(c)), N(n + 1), B(m), D(m + 2, vd(n + 2)) {
    FOR(i, 0, m) FOR(j, 0, n) D[i][j] = A[i][j];
    FOR(i, 0, m) {
      B[i] = n + i;
      D[i][n] = -1;
      D[i][n + 1] = b[i];
    }
    FOR(j, 0, n) {
      N[j] = j;
      D[m][j] = -c[j];
    }
    N[n] = -1;
    D[m + 1][n] = 1;
  }

  void pivot(int r, int s) {
    T *a = D[r].data(), inv = 1 / a[s];
    FOR(i, 0, m + 2) if (i != r && abs(D[i][s]) > eps) {
      T *b = D[i].data(), inv2 = b[s] * inv;
      FOR(j, 0, n + 2) b[j] -= a[j] * inv2;
      b[s] = a[s] * inv2;
    }
    FOR(j, 0, n + 2) if (j != s) D[r][j] *= inv;
    FOR(i, 0, m + 2) if (i != r) D[i][s] *= -inv;
    D[r][s] = inv;
    swap(B[r], N[s]);
  }

  bool simplex(int phase) {
    int x = m + phase - 1;
    for (;;) {
      int s = -1;
      FOR(j, 0, n + 1) if (N[j] != -phase) ltj(D[x]);
      if (D[x][s] >= -eps) return true;
      int r = -1;
      FOR(i, 0, m) {
        if (D[i][s] <= eps) continue;
        if (r == -1 ||
            MP(D[i][n + 1] / D[i][s], B[i]) < MP(D[r][n + 1] / D[r][s], B[r]))
          r = i;
      }
      if (r == -1) return false;
      pivot(r, s);
    }
  }

  T solve(vd& x) {
    int r = 0;
    FOR(i, 1, m) if (D[i][n + 1] < D[r][n + 1]) r = i;
    if (D[r][n + 1] < -eps) {
      pivot(r, n);
      if (!simplex(2) || D[m + 1][n + 1] < -eps) return -inf;
      FOR(i, 0, m) if (B[i] == -1) {
        int s = 0;
        FOR(j, 1, n + 1) ltj(D[i]);
        pivot(i, s);
      }
    }
    bool ok = simplex(1);
    x = vd(n);
    FOR(i, 0, m) if (B[i] < n) x[B[i]] = D[i][n + 1];
    return ok ? D[m][n + 1] : inf;
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vd b(n), c(m);
  FOR(i, 0, n) { cin >> b[i]; }
  vvd a(n, vd(m));
  FOR(i, 0, m) {
    FOR(j, 0, n) {
      cin >> a[j][i];
      a[j][i] /= 100;
    }
    cin >> c[i];
  }

  vd x;
  T ans = LPSolver(a, b, c).solve(x);
  cout << setprecision(2) << fixed;
  cout << ans << ENDL;

  return 0;
}