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

// 112345678912345678912

void solve() {
  int n;
  cin >> n;
  vi ans;
  ans.pb(1);
  int curr = 1;
  FOR(i, 0, n - 3) {
    ans.pb(curr);
    curr++;
  }
  ans.pb(1);
  ans.pb(2);
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}