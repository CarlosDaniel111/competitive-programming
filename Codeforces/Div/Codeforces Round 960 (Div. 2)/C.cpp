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
  ll n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n) { cin >> a[i]; }
  ll suma = 0;

  auto check = [&]() -> bool {
    // checar
    vi vis(n + 1, 0);
    FOR(i, 0, n) {
      if (a[i] == 0) continue;
      vis[a[i]]++;
    }
    FOR(i, 1, n + 1) {
      if (vis[i] == 1) return false;
    }
    return true;
  };

  while (true) {
    FOR(i, 0, n) { suma += a[i]; }
    ll mx = 0;
    vector<ll> vis(n + 1, 0);
    FOR(i, 0, n) {
      vis[a[i]]++;
      if (vis[a[i]] == 2) mx = max(mx, a[i]);
      a[i] = mx;
    }
    if (check()) break;
  }

  ll suma2 = 0;
  FOR(i, 0, n) { suma2 += a[i]; }
  ROF(i, n, 0) {
    suma += suma2;
    suma2 -= a[i];
  }
  cout << suma << ENDL;

  /*ll curr = -1, suma2 = 0, cnt = 0;
  FOR(i, 0, n) {
    if (a[i] == 0) continue;
    if (curr == -1) {
      curr = a[i], suma2 = a[i], cnt = 1;
      continue;
    }
    if (a[i] == curr) {
      suma2 += a[i];
      cnt++;
      continue;
    }
    ll veces = n - i + 1;
    suma += veces * suma2;
    // cout << suma2 << " " << veces << ENDL;
    FOR(i, 1, cnt + 1) { suma += i * curr; }
    suma2 = a[i];
    curr = a[i];
    cnt = 1;
  }
  if (curr != -1) {
    FOR(i, 1, cnt + 1) { suma += i * curr; }
  }

  cout << suma << ENDL;*/
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}