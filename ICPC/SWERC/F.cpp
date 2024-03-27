#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

ll f[2025], g[2025];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll r, n, p;
  cin >> r >> n >> p;
  f[1] = 1;
  FOR(i, 2, n + 1) {
    FOR(j, 0, n + 1)
    g[j] = f[j];
    FOR(j, 1, i + 1) {
      f[j] = g[j - 1];
      if (i == r) continue;
      f[j] = (f[j] + 1ll * j * g[j]) % p;
      f[j] = (f[j] + 1ll * j * (j + 1) / 2 * g[j + 1]) % p;
    }
  }
  cout << f[1] << ENDL;

  return 0;
}