#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, p, h;
  cin >> n >> p >> h;
  vi sum, mul;
  ll attacks = 0, totsum = 0, totmul = 1;
  FOR(i, 0, n) {
    char c;
    ll x;
    cin >> c;
    if (c == '!')
      attacks++;
    else if (c == '+') {
      cin >> x;
      sum.pb(x);
      totsum += x;
    } else {
      cin >> x;
      mul.pb(x);
      totmul = min(2000000000ll, totmul * x);
    }
  }
  sort(sum.rbegin(), sum.rend());
  sort(mul.rbegin(), mul.rend());

  auto brute = [&](ll power, ll rem_h) -> ll {
    ll mn = 1e9;
    for (ll i = 0; i <= SZ(sum); i++) {
      ll curr = power;
      for (ll j = 0; j <= SZ(mul); j++) {
        for (ll k = 1; k <= attacks; k++) {
          if (curr * k >= rem_h) mn = min(mn, i + j + k);
        }
        if (j < SZ(mul)) curr *= mul[j];
      }
      if (i < SZ(sum)) power += sum[i];
    }
    return mn;
  };

  if (attacks == 0 or (p == 0 && totsum == 0 && totmul == 1)) {
    cout << "*" << ENDL;
    return 0;
  }
  if (totsum == 0 && totmul == 1) {
    int totattacks = (h + p - 1) / p;
    int aux = 0;
    if (totattacks % attacks == 0) aux = -SZ(mul);
    cout << totattacks + SZ(mul) * (totattacks / attacks) + aux << ENDL;
    return 0;
  }
  ll ans = 0;
  while (true) {
    ll mxpower = p;
    mxpower += totsum;
    mxpower *= totmul;
    if (mxpower * attacks >= h) {
      ans += brute(p, h);
      cout << ans << ENDL;
      return 0;
    }
    p = mxpower;
    h = h - mxpower * attacks;
    ans += n;
  }

  return 0;
}