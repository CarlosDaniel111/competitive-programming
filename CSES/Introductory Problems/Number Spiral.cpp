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

  int t;
  cin >> t;
  while (t--) {
    ll Y, X;
    cin >> Y >> X;
    if (Y > X) {
      if (Y % 2 != 0)
        cout << (Y - 1) * (Y - 1) + X << ENDL;
      else
        cout << (Y - 1) * (Y - 1) + (2 * Y - X) << ENDL;
    } else {
      if (X % 2 == 0)
        cout << (X - 1) * (X - 1) + Y << ENDL;
      else
        cout << (X - 1) * (X - 1) + (2 * X - Y) << ENDL;
    }
  }

  return 0;
}