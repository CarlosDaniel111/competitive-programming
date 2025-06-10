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
  string s;
  cin >> s;
  vi mp(1 << 26, n);
  int curr = 0;
  mp[0] = -1;
  int ans = 1;
  FOR(i, 0, n) {
    curr ^= 1 << (s[i] - 'a');
    ans = max(ans, i - mp[curr]);
    FOR(k, 0, 26) { ans = max(ans, i - mp[curr ^ (1 << k)]); }
    mp[curr] = min(mp[curr], i);
  }
  cout << ans << ENDL;

  return 0;
}