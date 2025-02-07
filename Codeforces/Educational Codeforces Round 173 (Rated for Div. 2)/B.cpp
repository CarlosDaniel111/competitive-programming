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
  int n, d;
  cin >> n >> d;
  vi ans;
  ans.pb(1);
  if (n >= 3 or d % 3 == 0) ans.pb(3);
  if (d == 5) ans.pb(5);
  if (n >= 3 or d == 7) ans.pb(7);
  if (n >= 6 or d == 9 or (d % 3 == 0 && n >= 3)) ans.pb(9);
  for (auto x : ans) cout << x << " ";
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}