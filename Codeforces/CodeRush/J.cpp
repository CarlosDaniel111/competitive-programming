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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> m >> n;
  double ans = 0;
  double ans2 = 0;
  bool dentro = false;
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      char c;
      cin >> c;
      if (c == '.' && dentro) {
        ans++;
      }
      if (c == '/' or c == '\\') dentro = !dentro, ans2++;
    }
  }
  cout << setprecision(2) << fixed;
  cout << ans + (ans2 / 2) << ENDL;

  return 0;
}