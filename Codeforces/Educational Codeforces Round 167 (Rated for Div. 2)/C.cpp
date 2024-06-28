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
  int n;
  cin >> n;
  vi a(n), b(n);
  FOR(i, 0, n)
  cin >> a[i];
  FOR(i, 0, n)
  cin >> b[i];

  int r1 = 0, r2 = 0, dar = 0, quitar = 0;
  FOR(i, 0, n) {
    if (a[i] == 1 && b[i] == 1) {
      dar++;
    } else if (a[i] == 1 && b[i] <= 0) {
      r1++;
    } else if (a[i] <= 0 && b[i] == 1) {
      r2++;
    } else if (a[i] == -1 && b[i] == -1) {
      quitar++;
    }
  }

  while (dar) {
    if (r1 < r2)
      r1++;
    else
      r2++;
    dar--;
  }
  while (quitar) {
    if (r1 > r2)
      r1--;
    else
      r2--;
    quitar--;
  }

  cout << min(r1, r2) << ENDL;
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