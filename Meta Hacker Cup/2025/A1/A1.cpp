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

void solve(int t) {
  int n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n) { cin >> a[i]; }
  int ans = 0;
  FOR(i, 0, n - 1) { ans = max(ans, abs(a[i] - a[i + 1])); }
  cout << "Case #" << t << ": " << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  FOR(i, 1, t + 1) solve(i);

  return 0;
}