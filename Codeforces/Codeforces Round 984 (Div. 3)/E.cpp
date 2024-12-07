#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

constexpr ll INF = 1e15 + 10;

void solve() {
  ll n, m, q;
  cin >> n >> m >> q;
  vector<vi> grid(n, vi(m));
  FOR(i, 0, n) FOR(j, 0, m) cin >> grid[i][j];
  vector<vi> reg(m, vi(n));
  FOR(i, 0, m) {
    ll curr = 0;
    FOR(j, 0, n) {
      curr |= grid[j][i];
      reg[i][j] = (curr);
    }
  }

  while (q--) {
    ll qq;
    cin >> qq;
    map<ll, pi> mp;
    int mn = n, mx = 0;
    while (qq--) {
      ll r, val;
      char c;
      cin >> r >> c >> val;
      r--;
      if (c == '<') {
        int pos2 = lower_bound(ALL(reg[r]), val) - reg[r].begin();
        mn = min(mn, pos2);
      } else {
        int pos = upper_bound(ALL(reg[r]), val) - reg[r].begin();
        mx = max(pos, mx);
      }
    }

    if (mx < mn) {
      cout << mx + 1 << ENDL;
    } else
      cout << -1 << ENDL;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  while (t--) solve();

  return 0;
}