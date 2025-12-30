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

  ll n, k;
  cin >> n >> k;
  ll LIM = 1 << k;
  vi f(LIM, 0);
  FOR(i, 0, n) {
    string s;
    cin >> s;
    ll x = stoi(s, nullptr, 2);
    f[x]++;
  }

  for (ll i = 0; i < k; ++i)
    for (ll mask = 0; mask < LIM; ++mask) {
      if (mask & (1 << i)) f[mask] += f[mask ^ (1 << i)];
    }
  FOR(i, 0, LIM) { f[i] = (f[i] * (f[i] - 1) * (f[i] - 2)) / 6; }
  for (ll i = 0; i < k; ++i)
    for (ll mask = 0; mask < LIM; ++mask) {
      if (mask & (1 << i)) f[mask] -= f[mask ^ (1 << i)];
    }

  ll q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    ll x = stoi(s, nullptr, 2);
    cout << f[x] << ENDL;
  }

  return 0;
}