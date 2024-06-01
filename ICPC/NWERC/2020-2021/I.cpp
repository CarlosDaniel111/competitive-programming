#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

vi t;
vector<vi> pt;
ll notCompatible[4][405][405];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  t.resize(n);
  pt.assign(3, vi(n, 0));
  FOR(i, 0, n)
  cin >> t[i];
  FOR(i, 0, 3) {
    FOR(j, 0, n) {
      cin >> pt[i][j];
    }
  }

  auto isNotCompatible = [&](ll p1, ll p2, ll s1, ll s2) -> bool {
    vector<pi> ocupado(n);
    bool vuelta = false;
    ll tiempo = 0;
    for (ll i = s1; i != s1 || !vuelta; i = (i + 1) % n) {
      ocupado[i] = {tiempo, tiempo + pt[p1][i]};
      tiempo += t[i] + pt[p1][i];
      vuelta = true;
    }
    vuelta = false;
    tiempo = 0;
    for (ll i = s2; i != s2 || !vuelta; i = (i + 1) % n) {
      vuelta = true;
      if (tiempo >= ocupado[i].second || tiempo + pt[p2][i] <= ocupado[i].first) {
        tiempo += t[i] + pt[p2][i];
      } else {
        return true;
      }
    }
    return false;
  };

  // simulaciones 0 - 1
  FOR(u, 0, 3) {
    int v = (u + 1) % 3;
    FOR(i, 0, n) {
      FOR(j, 0, n) {
        notCompatible[u][i][j] = isNotCompatible(u, v, i, j);
      }
    }
  }

  FOR(i, 0, n) {
    FOR(j, 0, n) {
      FOR(k, 0, n) {
        if (notCompatible[0][i][j] || notCompatible[1][j][k] || notCompatible[2][k][i]) continue;
        cout << i + 1 << " " << j + 1 << " " << k + 1 << ENDL;
        return 0;
      }
    }
  }
  cout << "impossible" << ENDL;

  return 0;
}