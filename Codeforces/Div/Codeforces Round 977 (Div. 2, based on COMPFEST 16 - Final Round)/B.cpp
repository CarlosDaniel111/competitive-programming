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
  ll n, d;
  cin >> n >> d;
  set<ll> usados;
  map<ll, multiset<ll>> usables;
  FOR(i, 0, n) {
    ll x;
    cin >> x;
    if (usados.count(x)) {
      usables[x % d].insert(x);
    } else
      usados.insert(x);
  }
  ll curr = 0;
  while (true) {
    if (usados.count(curr)) {
      curr++;
      continue;
    }
    if (SZ(usables[curr % d]) && *usables[curr % d].begin() <= curr) {
      usables[curr % d].erase(usables[curr % d].begin());
      curr++;
      continue;
    }
    cout << curr << ENDL;
    return;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}