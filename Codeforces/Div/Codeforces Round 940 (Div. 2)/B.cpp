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

#define setBit(S, j) (S |= (1 << j))

void solve() {
  ll n, k;
  cin >> n >> k;
  if (n == 1) {
    cout << k << ENDL;
    return;
  }
  ll suma = 0;
  FOR(i, 0, 64) {
    ll aux = (suma | (1 << i));
    if (aux <= k) {
      suma |= (1 << i);
    } else
      break;
  }
  cout << suma << " " << k - suma << " ";
  FOR(i, 2, n) {
    cout << 0 << " ";
  }
  cout << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}