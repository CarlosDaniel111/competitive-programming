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

void solve() {
  ll n, q;
  string s1, s2;
  cin >> n >> q;
  cin >> s1 >> s2;
  vector<vi> pre(n + 1, vi(26, 0));
  FOR(i, 1, n + 1) {
    FOR(j, 0, 26) {
      ll is = j == (s1[i - 1] - 'a');
      pre[i][j] = pre[i - 1][j] + is;
    }
  }

  vector<vi> pre2(n + 1, vi(26, 0));
  FOR(i, 1, n + 1) {
    FOR(j, 0, 26) {
      ll is = j == (s2[i - 1] - 'a');
      // f (is) cout << j << ENDL;
      pre2[i][j] = pre2[i - 1][j] + is;
    }
  }

  while (q--) {
    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    FOR(i, 0, 26) {
      ll x = pre[r][i] - pre[l - 1][i];
      // cout << char('a' + i) << " " << x << ENDL;
      ll y = pre2[r][i] - pre2[l - 1][i];
      // cout << char('a' + i) << " " << y << ENDL;
      ans += abs(x - y);
    }
    cout << ans / 2 << ENDL;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}