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
  ll mx = 0, imparmx = 0;
  ll par = 0, impar = 0;
  FOR(i, 0, n) {
    cin >> a[i];
    mx = max(mx, a[i]);
    par += (a[i] % 2 == 0);
    impar += (a[i] % 2 == 1);
    if (a[i] % 2 == 1) imparmx = max(imparmx, a[i]);
  }

  if (par == 0 || impar == 0) {
    cout << 0 << ENDL;
    return;
  }
  ll ans = 0;
  sort(a.begin(), a.end());
  FOR(i, 0, n) {
    if (a[i] < imparmx && a[i] % 2 == 0) {
      par--;
      imparmx = a[i] + imparmx;
      ans++;
    }
  }

  if (mx % 2 == 0 && mx > imparmx) ans++;
  ans += par;
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}