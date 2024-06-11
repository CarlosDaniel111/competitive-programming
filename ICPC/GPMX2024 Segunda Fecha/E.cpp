#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define ALL(x) begin(x), end(x)
#define SZ(x) ((ll)x.size())
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; i++)
#define ENDL '\n'

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  vector<pi> c(n);
  FOR(i, 0, n) {
    cin >> c[i].first;
    c[i].first--;
    c[i].second = i;
  }

  sort(ALL(c));

  FOR(i, 0, n) {
    if (c[i].first > i) {
      cout << -1 << ENDL;
      return 0;
    }
  }

  ll ans = 0;
  FOR(i, 0, n) { ans += c[i].first; }
  cout << ans << ENDL;
  FOR(i, 0, n) {
    FOR(j, 0, c[i].first) {
      cout << c[i].second + 1 << " " << c[j].second + 1 << ENDL;
    }
  }
}