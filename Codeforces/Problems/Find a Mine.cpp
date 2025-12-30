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

void solve() {
  auto ask = [](ll x, ll y) -> int {
    if (x <= 0 or y <= 0) return -1;
    cout << "? " << x << " " << y << endl;
    ll d;
    cin >> d;
    return d;
  };
  ll n, m;
  cin >> n >> m;
  ll d1 = ask(1, 1);
  if (d1 == 0) {
    cout << "! " << 1 << " " << 1 << endl;
    return;
  }
  ll d2 = ask(1, m);
  if (d2 == 0) {
    cout << "! " << 1 << " " << m << endl;
    return;
  }
  ll x = d1 + d2 + 3 - m;
  if (x > 0 && x % 2 == 0) {
    x /= 2;
    ll y = d1 + 2 - x;
    if (ask(x, y) == 0) {
      cout << "! " << x << " " << y << endl;
      return;
    }
  }

  ll d3 = ask(n, 1);
  ll y = d1 + d3 + 3 - n;
  y /= 2;
  x = d1 + 2 - y;
  cout << "! " << x << " " << y << endl;
  return;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}