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

  ll k;
  cin >> k;
  vi a(k);
  FOR(i, 0, k) cin >> a[i];
  ll n;
  cin >> n;
  vector<vi> b(n, vi(k));
  vi sum(k, 0);
  FOR(i, 0, n) {
    FOR(j, 0, k) {
      cin >> b[i][j];
      sum[j] += b[i][j];
    }
  }
  ll round = 1e18;
  FOR(i, 0, k) {
    if (sum[i] == 0) continue;
    round = min(round, a[i] / sum[i]);
  }
  FOR(i, 0, k) a[i] -= sum[i] * round;
  FOR(i, 0, n) {
    FOR(j, 0, k) {
      a[j] -= b[i][j];
      if (a[j] < 0) {
        cout << round + 1 << " " << i + 1 << ENDL;
        return 0;
      }
    }
  }

  return 0;
}