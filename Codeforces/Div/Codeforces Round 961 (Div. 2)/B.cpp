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
  ll n, m;
  cin >> n >> m;
  map<ll, ll> mapa;
  FOR(i, 0, n) {
    ll x;
    cin >> x;
    mapa[x]++;
  }

  ll ans = 0;

  for (auto &[petalos, cnt] : mapa) {
    ll alcance = min(cnt, m / petalos);
    ll curr = alcance * petalos;
    if (mapa.count(petalos + 1)) {
      ll cntSig = mapa[petalos + 1];
      ll alcanceSig = min(cntSig, (m - curr) / (petalos + 1));
      curr += alcanceSig * (petalos + 1);
      curr = min(m, curr + min(cntSig - alcanceSig, alcance));
    }
    ans = max(ans, curr);
  }
  cout << ans << ENDL;
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