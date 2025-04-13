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
  int cntImpar = 0, cntPar = 0;
  cin >> s;
  FOR(i, 0, n) {
    if (i & 1)
      cntImpar += (s[i] == '1');
    else
      cntPar += (s[i] == '1');
  }
  cin >> s;
  FOR(i, 0, n) {
    if (i & 1)
      cntPar += (s[i] == '1');
    else
      cntImpar += (s[i] == '1');
  }
  if (cntImpar <= (n + 1) / 2 && cntPar <= n / 2) {
    cout << "YES" << ENDL;
  } else {
    cout << "NO" << ENDL;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}