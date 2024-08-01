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

  string a[2];
  cin >> a[0] >> a[1];

  int ans = 0;

  FOR(i, 1, n - 1) {
    FOR(j, 0, 2) {
      if (a[j][i] == '.' && a[j ^ 1][i] == '.' && a[j][i + 1] == '.' && a[j][i - 1] == '.' && a[j ^ 1][i + 1] == 'x' && a[j ^ 1][i - 1] == 'x')
        ans++;
    }
    }
  cout << ans << "\n";
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