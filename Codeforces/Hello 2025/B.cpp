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
  int n, k;
  cin >> n >> k;
  map<int, int> cnt;
  FOR(i, 0, n) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  vi a;
  for (auto &[x, y] : cnt) {
    a.pb(y);
  }
  sort(ALL(a));
  int i = 0;
  int ans = SZ(a);
  FOR(i, 0, SZ(a)) {
    if (a[i] > k) break;
    k -= a[i];
    ans--;
  }
  cout << max(1, ans) << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}