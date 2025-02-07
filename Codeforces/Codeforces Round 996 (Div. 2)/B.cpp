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

bool cmp(pi a, pi b) { return ((a.first - a.second) < (b.first - b.second)); }

void solve() {
  ll n;
  cin >> n;
  vector<pi> a(n);
  FOR(i, 0, n) cin >> a[i].first;
  FOR(i, 0, n) cin >> a[i].second;

  sort(ALL(a), cmp);

  ll debo = 0;
  FOR(i, 0, n) {
    ll aa = a[i].first - debo;
    ll bb = a[i].second;
    if (aa < bb) {
      if (debo > 0) {
        cout << "NO" << ENDL;
        return;
      }
      debo += bb - aa;
    }
  }

  cout << "YES" << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}