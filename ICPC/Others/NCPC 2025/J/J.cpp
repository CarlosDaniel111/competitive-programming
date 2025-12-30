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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int solve(int n, int e) {
  ll t = 0;
  set<pi> mp;
  int c = 0;
  while (e >= 0) {
    c++;
    if (c > n * 3) {
      return 0;
    }
    // cout << "E " << e << " " << "T " << t << " --- " << e % n << " " << t % n
    // << '\n';
    if (mp.count({e % n, t % n})) {
      return 1;
    }
    mp.insert({e % n, t % n});
    t += e;
    if (t % n == 0)
      e++;
    else
      e--;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  FOR(i, 0, 10000000) {
    int n = uniform_int_distribution<int>(1, 300000)(rng);
    int e = uniform_int_distribution<int>(1, 1000000000)(rng);
    if (!solve(n, e)) {
      cout << n << " " << e << ENDL;
      cout << "weeep" << ENDL;
      return 0;
    }
  }

  return 0;
}