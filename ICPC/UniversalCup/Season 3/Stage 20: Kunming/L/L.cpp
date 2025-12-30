#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ENDL '\n'

void solve() {
  int n, m;
  cin >> n >> m;
  int golpea = 0;
  bool f = false;
  vector<int> explota(n + n + m + 5, 0);
  FOR(i, 0, n) {
    ll x;
    cin >> x;
    if (x == 1) {
      if (!f) {
        golpea++;
        f = true;
      }
    } else
      golpea++;
    if (x <= n + n + m) explota[x - 1]++;
  }
  vector<ll> a(m);
  FOR(i, 0, m) { cin >> a[i]; }
  sort(a.begin(), a.end());
  if (a.back() > n + n + m) {
    cout << "No" << ENDL;
    return;
  }

  int currExplotado = explota[0], i = 1;
  for (auto enemigo : a) {
    for (; i <= currExplotado; i++) {
      currExplotado += explota[i];
    }
    if (enemigo > currExplotado) {
      if (enemigo > currExplotado + golpea) {
        cout << "No" << ENDL;
        return;
      }
      golpea -= enemigo - currExplotado;
    }
    currExplotado++;
  }
  cout << "Yes" << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}