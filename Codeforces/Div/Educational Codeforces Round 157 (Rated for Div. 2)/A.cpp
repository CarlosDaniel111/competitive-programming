#include <bits/stdc++.h>
using namespace std;
// AC2++
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    ll x, y, s;
    cin >> x >> y >> s;
    ll ans = 0;
    if (x <= y) {
      ans += x;
      y -= x;
      if (y <= s) {
        ans += y;
        cout << ans << ENDL;
        continue;
      } else {
        ans += s;
        y -= s;
        ans += (y * 2);
        cout << ans << ENDL;
        continue;
      }
    } else {
      ans += x;
      cout << ans << ENDL;
      continue;
    }
  }

  return 0;
}