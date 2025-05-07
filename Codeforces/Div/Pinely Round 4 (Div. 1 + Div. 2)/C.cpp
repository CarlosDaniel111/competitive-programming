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
  ll n;
  cin >> n;
  vi a(n);
  bool par = false, impar = false;
  FOR(i, 0, n) { cin >> a[i]; }

  sort(ALL(a));
  a.resize(unique(ALL(a)) - a.begin());

  vi ans;
  ans.clear();
  FOR(i, 0, 39) {
    ll medio = (*max_element(ALL(a)) + *min_element(ALL(a))) / 2;
    ans.pb(medio);
    FOR(j, 0, SZ(a)) { a[j] = abs(a[j] - medio); }
  }
  ans.pb(a[0]);

  sort(ALL(a));
  a.resize(unique(ALL(a)) - a.begin());
  if (SZ(a) > 1) {
    cout << -1 << ENDL;
    return;
  }

  cout << SZ(ans) << ENDL;
  for (auto x : ans) {
    cout << x << " ";
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