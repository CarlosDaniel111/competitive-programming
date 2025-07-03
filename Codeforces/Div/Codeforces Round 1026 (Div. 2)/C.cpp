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
  vi d(n);
  FOR(i, 0, n) cin >> d[i];
  vector<pi> obs(n);
  FOR(i, 0, n) cin >> obs[i].first >> obs[i].second;

  int curr = 0;
  vi pos;
  FOR(i, 0, n) {
    if (d[i] == -1)
      pos.pb(i);
    else
      curr += d[i];

    while (curr < obs[i].first) {
      if (!SZ(pos)) {
        cout << -1 << ENDL;
        return;
      }
      d[pos.back()] = 1;
      pos.pop_back();
      curr++;
    }
    while (curr + SZ(pos) > obs[i].second) {
      if (!SZ(pos)) {
        cout << -1 << ENDL;
        return;
      }
      d[pos.back()] = 0;
      pos.pop_back();
    }
  }
  FOR(i, 0, n) cout << max(0, d[i]) << " ";
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}