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
  int l = 0, r = SZ(s);
  while (l < r - 1 && s[l] == s[r - 1]) l++, r--;
  s = s.substr(l, r - l);
  int n = SZ(s);
  auto can = [&](int x) -> bool {
    vi cnt(26, 0);
    FOR(i, 0, x) cnt[s[i] - 'a']++;
    FOR(i, 0, min(n / 2, n - x)) {
      char c = s[n - i - 1];
      if (i < x)
        cnt[c - 'a']--;
      else if (s[i] != c)
        return false;
    }
    FOR(i, 0, 26) {
      if (cnt[i] < 0 or (cnt[i] & 1)) return false;
    }
    return true;
  };

  int ans = n;
  FOR(_, 0, 2) {
    l = 0, r = n;
    while (l < r) {
      int mid = (l + r) / 2;
      if (can(mid))
        r = mid;
      else
        l = mid + 1;
    }
    ans = min(ans, l);
    reverse(ALL(s));
  }
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}