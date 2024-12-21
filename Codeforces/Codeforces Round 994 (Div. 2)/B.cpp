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
  string s;
  cin >> s;
  int cntp = 0, cnts = 0, cntpt = 0;
  int mnp = 1e9, mxp = -1, mns = 1e9, mxs = -1;
  FOR(i, 0, n) {
    cntp += (s[i] == 'p');
    cnts += (s[i] == 's');
    cntpt += (s[i] == '.');
    if (s[i] == 'p') {
      mnp = min(mnp, i);
      mxp = max(mxp, i);
    }
    if (s[i] == 's') {
      mns = min(mns, i);
      mxs = max(mxs, i);
    }
  }
  if (cntp == 0 or cnts == 0) {
    cout << "YES" << ENDL;
    return;
  }
  if (s[0] == '.' && s[n - 1] == '.') {
    cout << "NO" << ENDL;
    return;
  }
  if (mxs > mnp) {
    cout << "NO" << ENDL;
    return;
  }
  if (cnts > 1 && cntp > 1) {
    cout << "NO" << ENDL;
    return;
  }
  if (cnts == 1 && cntp > 1 && s[0] == '.') {
    cout << "NO" << ENDL;
    return;
  }

  if (cntp == 1 && cnts > 1 && s[n - 1] == '.') {
    cout << "NO" << ENDL;
    return;
  }
  cout << "YES" << ENDL;
}
// .spp
// 3214
signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}