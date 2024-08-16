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
  set<int> s;
  int xx = -1, yy = -1;
  FOR(i, 0, n) {
    int x;
    cin >> x;
    if (xx == -1 || x == xx)
      xx = x;
    else
      yy = x;
    s.insert(x);
  }
  if (SZ(s) == 1) {
    cout << "YES" << ENDL;
  } else if (SZ(s) == 2 && abs(xx - yy) > 1) {
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