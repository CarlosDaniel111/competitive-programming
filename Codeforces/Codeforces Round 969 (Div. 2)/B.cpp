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
  ll n, m;
  cin >> n >> m;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  ll mx = 0;
  FOR(i, 0, n) { mx = max(mx, a[i]); }
  while (m--) {
    char c;
    ll l, r;
    cin >> c >> l >> r;
    if (c == '+') {
      if (mx >= l && mx <= r) mx++;
    } else {
      if (mx >= l && mx <= r) mx--;
    }
    cout << mx << " ";
  }
  cout << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}