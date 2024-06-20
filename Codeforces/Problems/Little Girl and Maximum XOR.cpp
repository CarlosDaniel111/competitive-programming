#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll a, b;
  cin >> a >> b;
  if (a == b) {
    cout << "0" << ENDL;
    return 0;
  }
  vi binA, binB;
  while (a) {
    binA.pb(a % 2);
    a /= 2;
  }
  while (b) {
    binB.pb(b % 2);
    b /= 2;
  }
  while (SZ(binA) < SZ(binB)) binA.pb(0);
  while (SZ(binA) > SZ(binB)) binB.pb(0);

  ll aux;
  ROF(i, SZ(binA), 0) {
    if (binA[i] != binB[i]) {
      aux = i + 1;
      break;
    }
  }
  ll ans = pow(2, aux) - 1;
  cout << ans << ENDL;

  return 0;
}