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
  if (n == 1) {
    cout << 1 << ENDL;
    return;
  }
  string s(n, '0');
  s[0] = '1';
  s[1] = '9';
  s[2] = '6';
  cout << s << ENDL;
  FOR(i, 0, (n - 1) / 2) {
    cout << 1;
    FOR(_, 0, i) cout << 0;
    cout << 6;
    FOR(_, 0, i) cout << 0;
    cout << 9;
    FOR(_, 0, (n - 3 - i * 2)) cout << 0;
    cout << ENDL;

    cout << 9;
    FOR(_, 0, i) cout << 0;
    cout << 6;
    FOR(_, 0, i) cout << 0;
    cout << 1;
    FOR(_, 0, (n - 3 - i * 2)) cout << 0;
    cout << ENDL;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}