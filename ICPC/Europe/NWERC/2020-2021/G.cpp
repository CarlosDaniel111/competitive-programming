#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vd = vector<double>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

int n, R, m, margen;
vi t, d;
vd p;
double x;
vector<vd> dp;

double solve(int i, int j) {
  if (i == m + 1) return 0;
  double &ans = dp[i][j];
  if (ans != -1) {
    return ans;
  }

  double noerror = p[i] * (t[i + 1] - t[i] + solve(i + 1, j));
  double error;
  // me puedo equivocar
  if (j + d[i] <= margen) {
    error =
        (1.0 - p[i]) * min(x, d[i] + t[i + 1] - t[i] + solve(i + 1, j + d[i]));
  } else {
    error = (1.0 - p[i]) * x;
  }
  ans = noerror + error;
  return ans;
}

constexpr double EPS = 1e-6;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> R >> m;
  margen = R - n - 1;
  t.assign(m + 5, 0), p.assign(m + 5, 0);
  d.resize(m + 5);
  FOR(i, 1, m + 1) { cin >> t[i] >> p[i] >> d[i]; }
  t[0] = d[0] = 0;
  p[0] = 1;
  double l = 0, r = 1e9;
  while (abs(r - l) > EPS) {
    double mid = (l + r) / 2;
    x = mid;
    dp.assign(m + 1, vd(margen + 1, -1));
    if (solve(0, 0) <= x)
      r = mid;
    else
      l = mid;
  }
  cout << setprecision(12) << fixed;
  cout << n + solve(0, 0) << ENDL;

  return 0;
}