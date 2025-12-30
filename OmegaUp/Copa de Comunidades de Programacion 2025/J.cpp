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

  vi cnt(10);
  cnt[0] = 6, cnt[1] = 2, cnt[2] = 5, cnt[3] = 5, cnt[4] = 4, cnt[5] = 5,
  cnt[6] = 6, cnt[7] = 3, cnt[8] = 7, cnt[9] = 6;

  string s;
  cin >> s;
  int tot = 0;
  for (auto c : s) tot += cnt[c - '0'];
  int n = SZ(s);
  string ans = "";
  FOR(i, 0, n) {
    for (int k = 9; k >= 0; k--) {
      int need = cnt[k];
      int sobra = tot - need;
      if (sobra >= (n - i - 1) * 2 && sobra <= (n - i - 1) * 7) {
        ans += (k + '0');
        tot -= need;
        break;
      }
    }
  }
  cout << ans << ENDL;

  return 0;
}