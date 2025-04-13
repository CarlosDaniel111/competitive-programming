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

ll n;
vi a;

ll solve1(ll mxi) {
  if (mxi == -1) return 0;
  priority_queue<ll> pqPar, pqImpar;
  ll ans = a[mxi];
  FOR(i, 0, n) {
    if (i == mxi) continue;
    if (a[i] & 1)
      pqImpar.push(a[i]);
    else
      pqPar.push(a[i]);
  }
  bool usado = false;
  while (true) {
    if (ans & 1) {
      if (!SZ(pqPar)) break;
      ans += pqPar.top();
      pqPar.pop();
      if (!usado && SZ(pqPar) == 0) {
        ans--;
        usado = true;
      }
    } else {
      if (!SZ(pqImpar)) break;
      ans += pqImpar.top() - 1;
      pqImpar.pop();
      if (SZ(pqImpar) == 0) {
        ans++;
        usado = true;
      }
    }
  }
  if (usado && ans % 2 == 0) ans++;
  return ans;
}

void solve() {
  cin >> n;
  a.resize(n);
  ll mxipar = -1, mxiimpar = -1;
  FOR(i, 0, n) {
    cin >> a[i];
    if (a[i] % 2 == 0 && (mxipar == -1 or a[mxipar] < a[i])) {
      mxipar = i;
    }
    if (a[i] % 2 == 1 && (mxiimpar == -1 or a[mxiimpar] < a[i])) {
      mxiimpar = i;
    }
  }
  cout << max(solve1(mxipar), solve1(mxiimpar)) << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}