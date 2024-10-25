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

int n;
vector<double> x, y;
vector<vector<double>> dp;

double calc(int u, int v) { return fabs(x[u] - x[v]) + fabs(y[u] - y[v]); }

double solve(int u, int msk) {
  if (msk == (1 << n) - 1) {
    return 0;
  }
  double &ans = dp[u][msk];
  if (ans >= 0) return ans;
  ans = 1e18;

  FOR(v, 0, n) {
    if ((msk >> v) & 1) continue;
    ans = min(ans, calc(u, v) + solve(v, msk | (1 << v)));
  }
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  vector<double> px(n), py(n);
  x.resize(n), y.resize(n);
  double ans = 1e18;
  FOR(i, 0, n) cin >> px[i] >> py[i];
  FOR(i, 0, n) {
    FOR(j, i + 1, n) {
      double ang = -atan2((py[j] - py[i]), (px[j] - px[i]));
      FOR(ii, 0, n) {
        x[ii] = px[ii] * cos(ang) - py[ii] * sin(ang);
        y[ii] = px[ii] * sin(ang) + py[ii] * cos(ang);
      }
      dp.assign(n, vector<double>(1 << n, -1));
      FOR(ii, 0, n) { ans = min(ans, solve(ii, 1 << ii)); }
    }
  }
  cout << setprecision(12) << fixed;
  cout << ans << ENDL;

  return 0;
}