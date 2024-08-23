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

vector<vi> g;
vector<bool> impares;
vi padre;

void dfs(int x, bool impar) {
  impares[x] = impar;
  for (auto y : g[x]) {
    if (y != padre[x]) {
      padre[y] = x;
      dfs(y, !impar);
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;
  g.assign(n + 5, vi());
  impares.assign(n + 5, 0);
  padre.assign(n + 5, 0);
  FOR(i, 1, n) {
    int x, y;
    cin >> x >> y;
    g[x].pb(y);
    g[y].pb(x);
  }
  if (n % 2 == 0) {
    cout << n << ENDL;
    return 0;
  }
  dfs(n, 0);
  vi cnt(n + 5, 0);
  vector<bool> vis(n + 5, 0);
  ROF(i, n + 1, 1) {
    if (impares[i] || SZ(g[i]) == 1) {
      cout << i << ENDL;
      return 0;
    }
    int p;
    for (p = i; p && !vis[p]; cnt[p = padre[p]]++) vis[p] = 1;
    if (p == n && cnt[p] >= 3 || p != n && cnt[p] >= 2 && !impares[p]) {
      cout << i << ENDL;
      return 0;
    }
  }

  return 0;
}