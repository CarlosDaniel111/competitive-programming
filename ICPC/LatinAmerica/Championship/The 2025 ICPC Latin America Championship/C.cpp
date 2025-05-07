#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int c, n;
  cin >> c >> n;
  vector<int> a(n);
  FOR(i, 0, n) cin >> a[i];
  for (int i = 51; i >= -51; i--) {
    int curr = c;
    bool valiomadre = false;
    FOR(j, 0, n) {
      if (a[j] >= i) {
        curr = c;
        continue;
      }
      if (curr == 0) {
        valiomadre = true;
        break;
      }
      curr--;
    }
    if (!valiomadre) {
      cout << i << '\n';
      return 0;
    }
  }

  return 0;
}