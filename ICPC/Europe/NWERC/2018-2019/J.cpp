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

  ll n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  sort(a.rbegin(), a.rend());

  vector<pi> grupos;
  FOR(i, 1, n) {
    ll cnt = 1;
    while (i < n - 1 && a[i] == a[i + 1]) {
      cnt++, i++;
    }
    grupos.pb({a[i], cnt});
  }

  ll mx = grupos[0].first, people = grupos[0].second;
  ll ans = 0, pasosTotal = 0, idx = 1;
  while (mx + log2(people) <= a[0]) {
    ll currMov = log2(people) + 1, currAdd = log2(people);
    pasosTotal += currMov;
    if (idx == SZ(grupos)) {
      ll aux = (a[0] - mx) / currAdd;
      ans += aux * currMov;
      mx += aux * currAdd;
      break;
    }
    ll diff = mx + currAdd - (pasosTotal + grupos[idx].first);
    if (diff > 0) {
      if (mx + (diff + 1) * currAdd > a[0]) {
        ll aux = (a[0] - mx) / currAdd;
        ans += aux * currMov;
        mx += aux * currAdd;
        break;
      } else {
        currAdd += diff * currAdd;
        pasosTotal += currMov * diff;
        currMov += diff * currMov;
      }
    }

    mx += currAdd;
    people += grupos[idx++].second;
    ans += currMov;
  }
  ans += a[0] - mx;
  cout << ans << ENDL;

  return 0;
}