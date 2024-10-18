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

  double n, p, k;
  cin >> n >> p >> k;

  double ans = 0;
  // no se mueve de la posicion
  ans += pow((p - 1) / n, k) * p;

  // se lavan i camisas
  FOR(i, p, n + 1) {
    ans += (i + 1) / 2.0 * (pow(i / n, k) - pow((i - 1) / n, k));
  }
  cout << setprecision(12) << fixed;
  cout << ans << ENDL;

  return 0;
}