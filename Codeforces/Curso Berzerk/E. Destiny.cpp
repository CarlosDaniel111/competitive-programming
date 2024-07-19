#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  vi a(n);
  vector<vi> pos(n + 1);
  FOR(i, 0, n) {
    cin >> a[i];
    pos[a[i]].pb(i);
  }

  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    l--, r--;
    int t = (r - l + 1) / k;
    int ans = 3e8;
    int len = r - l + 1;
    FOR(_, 0, 70) {
      int x = l + rng() % len;
      if (SZ(pos[a[x]]) < t) continue;
      int veces = upper_bound(ALL(pos[a[x]]), r) - lower_bound(ALL(pos[a[x]]), l);
      if (veces > t) {
        ans = min(ans, a[x]);
      }
    }
    if (ans == 3e8)
      cout << "-1" << ENDL;
    else
      cout << ans << ENDL;
  }

  return 0;
}