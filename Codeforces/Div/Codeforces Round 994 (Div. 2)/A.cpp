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
  int n, cnt0 = 0;
  int aux = -2;
  cin >> n;
  FOR(i, 0, n) {
    int x;
    cin >> x;
    cnt0 += (x == 0);
    if (x != 0 && aux == -2) aux = -1;
    if (x == 0 && aux == -1) aux = 0;
    if (x != 0 && aux == 0) aux = 1;
  }
  if (cnt0 == n) {
    cout << 0 << ENDL;
  } else if (aux == 1) {
    cout << 2 << ENDL;
  } else {
    cout << 1 << ENDL;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}