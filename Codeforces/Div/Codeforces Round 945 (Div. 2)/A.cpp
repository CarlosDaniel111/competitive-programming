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
  int a, b, c;
  cin >> a >> b >> c;
  if ((a + b + c) & 1) {
    cout << "-1" << ENDL;
    return;
  }
  int ans = b - a;

  c -= (b - a);
  b = a;
  ans += min(a * 2, c);

  b -= (c / 2);

  ans += max(0, b);
  cout << ans << ENDL;
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