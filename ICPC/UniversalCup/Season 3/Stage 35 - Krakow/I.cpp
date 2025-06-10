#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

template <int MOD>
struct mi {
  int v;
  mi() : v(0) {}
  mi(ll _v) : v(int(_v % MOD)) { v += (v < 0) * MOD; }
  mi& operator+=(mi o) {
    if ((v += o.v) >= MOD) v -= MOD;
    return *this;
  }
  mi& operator-=(mi o) {
    if ((v -= o.v) < 0) v += MOD;
    return *this;
  }
  mi& operator*=(mi o) {
    v = int((ll)v * o.v % MOD);
    return *this;
  }
  friend mi be(mi a, ll p) {
    assert(p >= 0);
    return p == 0 ? 1 : be(a * a, p / 2) * (p & 1 ? a : 1);
  }
  friend mi inv(mi a) {
    assert(a.v != 0);
    return be(a, MOD - 2);
  }
  friend mi operator+(mi a, mi b) { return a += b; }
  friend mi operator-(mi a, mi b) { return a -= b; }
  friend mi operator*(mi a, mi b) { return a *= b; }
};
using modint = mi<998244353>;

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<modint> a_mod(n);
  vector<modint> pref(n + 1, 0);
  vector<modint> pref2(n + 1, 0);
  FOR(i, 0, n) { cin >> a[i]; }
  sort(ALL(a));
  FOR(i, 0, n) {
    a_mod[i] = modint(a[i]);
    pref[i + 1] = pref[i] + a_mod[i];
    pref2[i + 1] = pref2[i] + (a_mod[i] * a_mod[i]);
  }
  modint ans = 0;
  FOR(i, 0, n) {
    ans += pref2[i];
    ll l = i + 1;
    while (l < n) {
      ll x = a[l] / a[i];
      ll r = lower_bound(a.begin(), a.end(), (x + 1) * a[i]) - a.begin();
      ans += modint(x) * modint(x) * (a_mod[i] * a_mod[i]) * modint(r - l);
      ans -= modint(2) * modint(x) * a_mod[i] * (pref[r] - pref[l]);
      ans += (pref2[r] - pref2[l]);
      l = r;
    }
  }
  cout << ans.v << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}