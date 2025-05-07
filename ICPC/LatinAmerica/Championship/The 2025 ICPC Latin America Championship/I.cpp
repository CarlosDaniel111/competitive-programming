#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

constexpr int MXN = 1e6 + 5;
int used[MXN];

struct Node {
  int ant, sig;
};
Node nodos[MXN];

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n) {
    cin >> a[i];
    used[a[i]] = 1;
  }
  FOR(i, 0, n) {
    if (i < n - 1)
      nodos[a[i]].sig = a[i + 1];
    else
      nodos[a[i]].sig = a[0];
    if (i > 0)
      nodos[a[i]].ant = a[i - 1];
    else
      nodos[a[i]].ant = a[n - 1];
  }
  int q;
  cin >> q;
  int cnt = 0;
  while (q--) {
    char c;
    cin >> c;
    if (c == '+') {
      int y, z;
      cin >> y >> z;
      used[y] = 1;
      int aux = nodos[z].ant;
      nodos[z].ant = y;
      nodos[y].sig = z;
      nodos[y].ant = aux;
      nodos[aux].sig = y;
    } else if (c == '-') {
      int x;
      cin >> x;
      used[x] = 0;
      nodos[nodos[x].ant].sig = nodos[x].sig;
      nodos[nodos[x].sig].ant = nodos[x].ant;
    } else {
      int m;
      cin >> m;
      vi b(m);
      FOR(i, 0, m) cin >> b[i];
      vi vis(m, 0);
      vi dp(m, -1);

      auto solve = [&](auto self, int pos) -> int {
        if (vis[pos]) return 1;             // Dio la vuelta
        if (dp[pos] != -1) return dp[pos];  // Ya lo calcule
        vis[pos] = 1;
        if (b[(pos + 1) % m] == nodos[b[pos]].sig) {
          dp[pos] = self(self, (pos + 1) % m) + 1;
        } else {
          dp[pos] = 1;
        }
        vis[pos] = 0;
        return dp[pos];
      };

      int ans = 0;
      FOR(i, 0, m) {
        if (used[b[i]]) ans = max(ans, solve(solve, i));
      }
      if (ans > m)
        cout << "*" << ENDL;
      else
        cout << ans << ENDL;
    }
  }

  return 0;
}