#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

constexpr int MOD = 998244353;
ll be(ll a, ll b, ll m = MOD) {
  ll res = 1;
  a %= m;
  while (b) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  vi p(n), q(n);
  FOR(i, 0, n) cin >> p[i];
  FOR(i, 0, n) cin >> q[i];
  int mxp = 0, mxq = 0;
  FOR(i, 0, n) {
    if (p[i] > p[mxp]) mxp = i;
    if (q[i] > q[mxq]) mxq = i;

    if (p[mxp] == q[mxq]) {
      if (p[i - mxq] > q[i - mxp])
        cout << (be(2, q[mxq]) + be(2, p[i - mxq])) % MOD << " ";
      else
        cout << (be(2, p[mxp]) + be(2, q[i - mxp])) % MOD << " ";
    } else if (p[mxp] > q[mxq]) {
      cout << (be(2, p[mxp]) + be(2, q[i - mxp])) % MOD << " ";
    } else {
      cout << (be(2, q[mxq]) + be(2, p[i - mxq])) % MOD << " ";
    }
  }
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}