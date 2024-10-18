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

void solve() {
  string s;
  cin >> s;
  int n = SZ(s);
  vector<vi> lcp(n + 1, vi(n + 1, 0));
  ROF(i, n, 0) {
    ROF(j, n, i + 1) {
      if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
    }
  }

  ll ans = 0;
  FOR(i, 0, n) {
    vi cnt(n + 1, 0);
    FOR(j, i + 2, n) {
      int w = min(lcp[i][j], j - i - 1);
      cnt[w]++;
    }
    ROF(j, n, 0) cnt[j] += cnt[j + 1];
    ROF(j, n, 0) cnt[j] += cnt[j + 1];
    FOR(k, 0, i) {
      if (lcp[k][i] >= i - k) {
        ans += cnt[i - k + 1];
      }
    }
  }
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}