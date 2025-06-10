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

struct Request {
  int d, p, c, lx, rx, ly, ry;
};

double expected_bonus(int t, const Request& req) {
  if (t > req.ry) return 0.0;
  double expected_x = (req.lx + req.rx) / 2.0;
  if (t <= req.ly) return expected_x;
  double prob = (double)(req.ry - t) / (req.ry - req.ly);
  return prob * expected_x;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<double> dp((1 << n), -1);
  vector<Request> req(n);
  FOR(i, 0, n)
  cin >> req[i].d >> req[i].p >> req[i].c >> req[i].lx >> req[i].rx >>
      req[i].ly >> req[i].ry;

  dp[0] = 0.0;
  FOR(mask, 0, (1 << n)) {
    if (dp[mask] < 0) continue;
    int currTime = 0;
    FOR(i, 0, n) if ((mask >> i) & 1) currTime += req[i].c;
    FOR(i, 0, n) {
      if ((mask >> i) & 1) continue;
      int ti = currTime + req[i].c;
      if (ti > req[i].d) continue;
      double add = expected_bonus(ti, req[i]) + req[i].p;
      int nxtMask = mask + (1 << i);
      dp[nxtMask] = max(dp[nxtMask], dp[mask] + add);
    }
  }

  cout << setprecision(10) << fixed;
  cout << *max_element(ALL(dp)) << ENDL;

  return 0;
}