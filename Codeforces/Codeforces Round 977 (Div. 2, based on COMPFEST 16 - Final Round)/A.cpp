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
  ll n, ultimo;
  cin >> n;
  vi par, impar;
  vi a(n);
  FOR(i, 0, n) { cin >> a[i]; }
  sort(ALL(a));

  // 2 4 6 8

  while (SZ(a) > 1) {
    sort(ALL(a));
    ll sum = a[0];
    a.erase(a.begin());
    sum += a[0];
    a.erase(a.begin());
    a.pb(sum / 2);
  }
  cout << a[0] << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}