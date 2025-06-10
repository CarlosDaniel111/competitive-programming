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

  int n;
  cin >> n;
  int ant = -1;
  ll ans = 0;
  FOR(i, 0, n) {
    int x;
    cin >> x;
    if (x >= ant) {
      ant = x;
      continue;
    }
    ans += ant - x;
  }
  cout << ans << ENDL;

  return 0;
}