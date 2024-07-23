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
  ll n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m, '0')), b(n, vector<char>(m, '0'));
  FOR(i, 0, n) { FOR(j, 0, m) cin >> a[i][j]; }
  FOR(i, 0, n) { FOR(j, 0, m) cin >> b[i][j]; }

  vector<vi> c(n, vi(m, 0));
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (a[i][j] == b[i][j]) continue;
      if (a[i][j] == '0') {
        c[i][j] = b[i][j] - a[i][j];
      } else if (a[i][j] == '1') {
        if (b[i][j] == '0') {
          c[i][j] = 2;
        } else {
          c[i][j] = b[i][j] - a[i][j];
        }
      } else {
        c[i][j] = b[i][j] + 1 - '0';
      }
    }
  }
  /*
    FOR(i, 0, n) {
      FOR(j, 0, m) { cout << c[i][j] << " "; }
      cout << ENDL;
    }
  */
  FOR(i, 0, n) {
    ll suma = 0;
    FOR(j, 0, m) { suma += c[i][j]; }
    if (suma % 3) {
      cout << "NO" << ENDL;
      return;
    }
  }

  FOR(j, 0, m) {
    ll suma = 0;
    FOR(i, 0, n) { suma += c[i][j]; }
    if (suma % 3) {
      cout << "NO" << ENDL;
      return;
    }
  }

  cout << "YES" << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}