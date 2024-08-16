#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

ll dist(ll x1, ll y1, ll x2, ll y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void solve() {
  int n;
  cin >> n;
  vector<pi> pts(n);
  FOR(i, 0, n) cin >> pts[i].first >> pts[i].second;
  ll xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  ll d = dist(xs, ys, xt, yt);
  FOR(i, 0, n) {
    ll d2 = dist(xt, yt, pts[i].first, pts[i].second);
    if (d2 <= d) {
      cout << "NO" << ENDL;
      return;
    }
  }
  cout << "YES" << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}