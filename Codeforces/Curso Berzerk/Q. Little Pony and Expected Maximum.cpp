#include <bits/stdc++.h>
using namespace std;

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
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  double m, n, ans = 0;
  cin >> m >> n;

  FOR(i, 1, m + 1) { ans += i * (pow((i / m), n) - pow((i - 1.0) / m, n)); }
  cout << setprecision(6) << fixed;

  cout << ans << ENDL;

  return 0;
}