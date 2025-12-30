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
  ll x;
  cin >> x;
  list<ll> ans;
  int mn = 0, mx = 500;
  while (x > 1) {
    if (x & 1) {
      ans.push_front(mn++);
      x--;
    } else {
      ans.push_front(mx--);
      x /= 2;
    }
  }
  cout << SZ(ans) << ENDL;
  for (auto y : ans) cout << y << " ";
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}