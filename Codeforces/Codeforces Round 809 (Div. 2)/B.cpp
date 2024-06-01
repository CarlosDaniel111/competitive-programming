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
  vi ultimo(n + 1, -1);
  vi ans(n, 0);
  FOR(i, 0, n) {
    int x;
    cin >> x;
    x--;
    if (ultimo[x] == -1) {
      ans[x] = 1;
      ultimo[x] = i;
      continue;
    }
    int dist = i - ultimo[x];
    if (dist % 2 == 1) {
      ans[x]++;
      ultimo[x] = i;
    }
  }

  FOR(i, 0, n) {
    cout << ans[i] << " ";
  }
  cout << ENDL;
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