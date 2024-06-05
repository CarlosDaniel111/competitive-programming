#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int L, W, H, l, w, h;
  cin >> L >> W >> H;
  cin >> l >> w >> h;
  int ans = 0;
  ans = max(ans, (L / l) * (W / w) * (H / h));
  ans = max(ans, (L / l) * (W / h) * (H / w));
  ans = max(ans, (L / w) * (W / l) * (H / h));
  ans = max(ans, (L / w) * (W / h) * (H / l));
  ans = max(ans, (L / h) * (W / l) * (H / w));
  ans = max(ans, (L / h) * (W / w) * (H / l));

  cout << ans << ENDL;

  return 0;
}