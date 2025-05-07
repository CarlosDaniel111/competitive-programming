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
  ll sum = 0;
  FOR(i, 0, n) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % n != 0) {
    cout << "NO" << ENDL;
    return;
  }
  ll prom = sum / n;
  FOR(i, 1, n - 1) {
    ll falta = prom - a[i - 1];
    a[i - 1] += falta;
    a[i + 1] -= falta;
  }
  FOR(i, 0, n) {
    if (a[i] != prom) {
      cout << "NO" << ENDL;
      return;
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