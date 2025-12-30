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
  vi p(n);
  vi deg(n, 0);
  FOR(i, 0, n) {
    cin >> p[i];
    p[i]--;
    deg[p[i]]++;
  }
  set<int> st;
  FOR(i, 0, n) if (deg[i] == 0) st.insert(i);
  int ans = 2;
  while (SZ(st)) {
    set<int> nxt;
    for (auto u : st) {
      int v = p[u];
      deg[v]--;
      if (deg[v] == 0) nxt.insert(v);
    }
    ans++;
    swap(st, nxt);
  }
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}