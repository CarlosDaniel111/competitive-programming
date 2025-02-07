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

vi x, z;
/*
  0 -> NO necesito carry
  1 -> Necesito carry
  2 -> Como sea
*/

ll dp[20][5][2];

ll solve(ll pos, ll opc, bool bajo) {
  if (pos == SZ(x)) {
    return (opc == 0 or opc == 2);
  }
  ll &ans = dp[pos][opc][bajo];
  if (ans != -1) return ans;
  ans = 0;
  ll lim = bajo ? 9 : z[pos];
  FOR(d, 0, lim + 1) {
    bool noNeedCarry = 0;
    if (opc == 0) {
      noNeedCarry = ((d == x[pos]) or (x[pos] == 0 && d < 5));
    } else if (opc == 1) {
      noNeedCarry = (x[pos] == 0 && d >= 5);
    } else {
      noNeedCarry = (d == x[pos] or x[pos] == 0);
    }

    bool needCarry = 0;
    if (opc == 0) {
      needCarry = ((d + 1 == x[pos]) or (x[pos] <= 1 && d < 5));
    } else if (opc == 1) {
      needCarry = ((x[pos] == 0 && d >= 4) or (x[pos] == 1 && d >= 5));
    } else {
      needCarry = ((d + 1 == x[pos]) or (x[pos] <= 1));
    }

    bool bajoNext = (bajo or d < z[pos]);
    if (noNeedCarry && needCarry) {
      ans += solve(pos + 1, 2, bajoNext);
    } else if (noNeedCarry) {
      ans += solve(pos + 1, 0, bajoNext);
    } else if (needCarry) {
      ans += solve(pos + 1, 1, bajoNext);
    }
  }
  return ans;
}

void solveCase() {
  x.clear(), z.clear();
  ll X;
  cin >> X;
  while (X) {
    x.pb(X % 10);
    X /= 10;
  }
  ll Z;
  cin >> Z;
  while (Z) {
    z.pb(Z % 10);
    Z /= 10;
  }
  while (SZ(x) < SZ(z)) x.pb(0);
  while (SZ(z) < SZ(x)) z.pb(0);
  reverse(ALL(x)), reverse(ALL(z));

  memset(dp, -1, sizeof(dp));
  cout << solve(0, 2, 0) << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t;
  cin >> t;
  while (t--) solveCase();

  return 0;
}