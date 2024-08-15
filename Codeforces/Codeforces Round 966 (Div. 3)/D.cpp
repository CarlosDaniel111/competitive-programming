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
  vector<ll> a(n);
  FOR(i, 0, n)
  cin >> a[i];
  string s;
  cin >> s;
  vi mn(n);
  int cnt = 0;
  ll ans = 0;
  FOR(i, 0, n) {
    cnt += (s[i] == 'L');
    mn[i] = cnt;
  }
  cnt = 0;
  ROF(i, n, 0) {
    cnt += (s[i] == 'R');
    ans += a[i] * min(cnt, mn[i]);
  }
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