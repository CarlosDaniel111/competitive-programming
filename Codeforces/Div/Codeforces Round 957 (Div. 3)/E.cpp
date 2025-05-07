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
  int n;
  cin >> n;
  string s = to_string(n);
  int len = SZ(s);
  while (SZ(s) < 8) s += s;
  vector<pi> ans;
  FOR(a, 1, 10001) {
    for (int b = min(10000, a * len - 1); b >= max(1, a * len - 8); b--) {
      if (stoi(s.substr(0, a * len - b)) == n * a - b) ans.pb({a, b});
    }
  }
  cout << SZ(ans) << ENDL;
  for (auto &[x, y] : ans) cout << x << " " << y << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}