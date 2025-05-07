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

using ld = long double;

struct Point{
    ld x,y;
    ld cross(Point p) const { return x * p.y - y * p.x; }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,k;
  cin >> n>>k;
  vector<Point> p(n);
  FOR(i,0,n) cin >> p[i].x >> p[i].y;

  vector<vector<ld>> c(n+5,vector<ld>(n+5,0));
  FOR(i, 0, n+5) {
    c[i][0] = c[i][i] = 1;
    FOR(j, 1, i) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
  }

  ld ans = 0;
  FOR(i,0,n){
    FOR(disp,k-1,n){
      auto p2 = p[(i+disp)%n];
      ans += p[i].cross(p2) * c[disp-1][k-2] / c[n][k];
    }
  }
  cout << setprecision(12)<<fixed;
  cout << ans/2 << ENDL;

  return 0;
}