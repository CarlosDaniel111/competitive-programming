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

void solve(ll t) {
  int n, a, b;
  cin >> n >> a >> b;
  cout << "Case #" << t << ": ";
  FOR(i, 0, n * 2) {
    if (i == n * 2 - 1) {
      cout << b << ENDL;
    } else {
      cout << "1 ";
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t;
  cin >> t;
  FOR(i, 1, t + 1) solve(i);

  return 0;
}