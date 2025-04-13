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
  if (SZ(s) < 3) {
    cout << "NO" << ENDL;
    return;
  }
  if (s[0] == '1' && s[1] == '0' && ((s[2] != '0' && s[2] != '1') || (s[2] == '1' && SZ(s) > 3))) {
    cout << "YES" << ENDL;
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