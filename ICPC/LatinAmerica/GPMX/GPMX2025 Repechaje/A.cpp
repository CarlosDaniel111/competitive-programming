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
  cin >> n >> m;
  vi a(m, 0);
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      int x;
      cin >> x;
      a[j] = max(x, a[j]);
    }
  }
  int ans = 0;
  for (auto x : a) ans += x;
  cout << ans << ENDL;

  return 0;
}