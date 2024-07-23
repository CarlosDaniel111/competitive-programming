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
  map<ll, ll> mapa;
  ll n;
  cin >> n;
  vi a(n);
  ll cnt = 0;
  FOR(i, 0, n) cin >> a[i];
  FOR(i, 1, n) {
    if (a[i] < a[i - 1]) {
      mapa[a[i - 1] - a[i]]++;
      a[i] = a[i - 1];
      cnt++;
    }
  }
  ll ans = 0, lleva = 0;
  for (auto x : mapa) {
    ans += (cnt + 1) * (x.first - lleva);
    cnt -= x.second;
    lleva = x.first;
  }
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