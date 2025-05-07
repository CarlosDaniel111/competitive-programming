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
  ll n, k;
  cin >> n >> k;
  vi a(n);
  FOR(i, 0, n)
  cin >> a[i];
  sort(ALL(a));
  ll curr = a[0];
  ll aux = 1;
  FOR(i, 1, n) {
    if (curr != a[i]) {
      ll dist = a[i] - curr;
      if (dist * aux > k) break;
      k -= dist * aux;
      curr = a[i];
    }
    aux++;
  }
  curr += k / aux;
  aux -= k % aux;

  cout << curr * n - aux + 1 << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}