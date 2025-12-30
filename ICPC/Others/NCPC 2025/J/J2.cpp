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

  ll n, e;
  cin >> n >> e;

  map<pi, pi> mp;
  ll t = 0;

  while (true) {
    if (e <= 0) {
      cout << t << ENDL;
      return 0;
    }

    t += e;
    if (t % n == 0)
      e++;
    else
      e--;

    if (e <= 0) {
      cout << t << ENDL;
      return 0;
    }

    ll r = t % n;
    ll emod = e % n;
    pi key = {r, emod};

    if (mp.count(key)) {
      auto [prevE, prevT] = mp[key];
      ll dE = e - prevE;
      ll dT = t - prevT;

      if (dE >= 0) {
        cout << "infinity" << ENDL;
        return 0;
      }

      ll veces = (e - 1) / (-dE);
      if (veces > 0) {
        ll addT = dT * veces;
        t += (long long)addT;
        e += dE * veces;
      }
    } else {
      mp[key] = {e, t};
    }
  }

  return 0;
}