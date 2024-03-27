#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

vector<pi> p;

pi solve(ll x) {
  if (p[x].first == -1) return {x, 0};
  pi boss = solve(p[x].first);
  p[x].first = boss.first;
  p[x].second += boss.second;
  return p[x];
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n, q;
  cin >> n >> q;
  p = vector<pi>(n + 1, {-1, 0});
  while (q--) {
    ll op, x, y;
    cin >> op;
    if (op == 1) {
      cin >> x >> y;
      p[x] = {y, 1};
    } else {
      cin >> x;
      pi ans = solve(x);
      cout << ans.second << ENDL;
    }
  }

  return 0;
}