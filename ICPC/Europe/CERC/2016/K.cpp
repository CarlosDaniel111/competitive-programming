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

  string s;
  cin >> s;
  int n = SZ(s);
  vi ans;
  auto change = [&](int pos) -> void {
    ans.pb(pos + 1);
    s[pos] = (s[pos] == '0' ? '1' : '0');
    s[pos + 1] = (s[pos + 1] == '0' ? '1' : '0');
  };
  int cnt = 1;
  FOR(i, 0, n - 1) {
    if (s[i] != s[i + 1]) cnt++;
  }
  int N = n / 3;
  if (cnt >= 2 * N) {
    cout << 0 << ENDL;
    return 0;
  }
  for (int i = 0; i < n; i += 3) {
    // 0011 -> 0101
    if (i && s[i - 1] == s[i] && s[i + 1] == s[i + 2]) change(i);
    // 000 -> 011
    else if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
      change(i + 1);
    else if (i && s[i - 1] == s[i] && s[i] == s[i + 1])
      change(i + 1);
  }
  cout << SZ(ans) << ENDL;
  for (auto x : ans) cout << x << " ";
  cout << ENDL;

  return 0;
}