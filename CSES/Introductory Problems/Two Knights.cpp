#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll K;
  cin >> K;
  FOR(k, 1, K + 1) {
    ll total = (k * k) * (k * k - 1) / 2;
    ll fail = 4 * (k - 1) * (k - 2);
    cout << total - fail << ENDL;
  }

  return 0;
}