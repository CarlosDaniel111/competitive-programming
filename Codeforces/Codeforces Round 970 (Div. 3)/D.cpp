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
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  string s;
  cin >> s;
  vi vis(n, -1);
  int cmp = 0;
  vi ans;
  FOR(i, 0, n) {
    if (vis[i] == -1) {
      int j = i;
      int cntN = 0;
      while (vis[j] == -1) {
        vis[j] = cmp;
        cntN += s[j] == '0';
        j = a[j] - 1;
      }
      ans.pb(cntN);
      cmp++;
    }
  }
  FOR(i, 0, n) { cout << ans[vis[i]] << " "; }
  cout << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}