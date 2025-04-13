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
  bool can = true;
  vi vis(n + 2);
  int x;
  cin >> x;
  vis[x] = 1;
  FOR(i, 1, n) {
    cin >> x;
    if (!vis[x - 1] && !vis[x + 1]) can = false;
    vis[x] = 1;
  }
  cout << (can ? "YES" : "NO") << ENDL;
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