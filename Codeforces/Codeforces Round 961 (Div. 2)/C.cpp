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
  FOR(i, 0, n)
  cin >> a[i];
  ll inicio = 0;
  while (inicio < n && a[inicio] == 1) inicio++;
  ll last = 0, ans = 0;
  FOR(i, inicio + 1, n) {
    if (a[i] == 1) {
      cout << -1 << ENDL;
      return;
    }
    ll ant = a[i - 1], curr = a[i];
    ll cnt = 0, cnt2 = 0;
    while (curr < ant) {
      curr *= curr;
      cnt++;
    }

    while (last && ant * ant <= a[i]) {
      ant *= ant;
      last--;
    }
    ll act = cnt + last;
    ans += act;
    last = act;
  }
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}