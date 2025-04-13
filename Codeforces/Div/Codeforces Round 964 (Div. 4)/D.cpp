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
  string s, t;
  cin >> s >> t;
  int j = 0;
  string ans = "";
  int cnt = 0;
  FOR(i, 0, SZ(t)) {
    while (j < SZ(s)) {
      if (s[j] == '?' || s[j] == t[i]) {
        ans += t[i];
        cnt++;
        j++;
        break;
      } else {
        ans += s[j];
        j++;
      }
    }
  }
  FOR(jj, j, SZ(s)) {
    if (s[jj] == '?')
      ans += 'a';
    else
      ans += s[jj];
  }
  if (cnt == SZ(t)) {
    cout << "YES" << ENDL;
    cout << ans << ENDL;
  } else {
    cout << "NO" << ENDL;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}