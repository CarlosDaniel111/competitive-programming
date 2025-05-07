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
  queue<int> q;
  q.push(1);
  vector<vi> pos(n + 1, vi());
  FOR(i, 2, n + 1) pos[1].pb(i);
  vector<pi> ans;
  while (SZ(q)) {
    int u = q.front();
    q.pop();
    for (auto v : pos[u]) {
      cout << "? " << u << " " << v << endl;
      int x;
      cin >> x;
      if (x == u) {
        ans.pb({u, v});
        q.push(v);
      } else {
        pos[x].pb(v);
      }
    }
  }

  cout << "! ";
  FOR(i, 0, n - 1) { cout << ans[i].first << " " << ans[i].second << " "; }
  cout << endl;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}