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
  int n, s, m;
  cin >> n >> s >> m;
  vector<pi> inter(n);
  FOR(i, 0, n) {
    cin >> inter[i].first >> inter[i].second;
  }
  sort(ALL(inter));
  int r = 0;
  FOR(i, 0, n) {
    if (inter[i].first - r >= s) {
      cout << "YES" << ENDL;
      return;
    }
    r = max(r, inter[i].second);
  }
  if (m - r >= s) {
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