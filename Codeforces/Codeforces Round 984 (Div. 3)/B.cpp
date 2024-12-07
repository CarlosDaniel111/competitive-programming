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
  int n, k;
  cin >> k >> n;
  map<int, int> mp;
  FOR(i, 0, n) {
    int x, y;
    cin >> x >> y;
    mp[x] += y;
  }
  vi mar;
  for (auto &[x, y] : mp) {
    mar.pb(y);
  }
  ll ans = 0;
  sort(mar.rbegin(), mar.rend());
  FOR(i, 0, min(k, SZ(mar))) { ans += mar[i]; }
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