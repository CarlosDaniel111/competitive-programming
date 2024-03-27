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

const int dx[4] = {1, 0, -1, 0},
          dy[4] = {0, 1, 0, -1};

pair<int, vi> hopcroftKarp(vector<vi>& g, int m) {
  int res = 0;
  vi btoa(m, -1), A(SZ(g)), B(m), cur, next;
  auto dfs = [&](auto self, int a, int L) -> bool {
    if (A[a] != L) return 0;
    A[a] = -1;
    for (int b : g[a])
      if (B[b] == L + 1) {
        B[b] = 0;
        if (btoa[b] == -1 || self(self, btoa[b], L + 1)) return btoa[b] = a, 1;
      }
    return 0;
  };
  while (1) {
    fill(ALL(A), 0);
    fill(ALL(B), 0);
    /// Encuentra los nodos restantes para BFS (i.e. con layer 0)
    cur.clear();
    for (int a : btoa)
      if (a != -1) A[a] = -1;
    FOR(a, 0, SZ(g))
    if (A[a] == 0) cur.pb(a);
    /// Encunetra todas las layers usando BFS
    for (int lay = 1;; lay++) {
      bool islast = 0;
      next.clear();
      for (int a : cur)
        for (int b : g[a]) {
          if (btoa[b] == -1) {
            B[b] = lay;
            islast = 1;
          } else if (btoa[b] != a && !B[b]) {
            B[b] = lay;
            next.pb(btoa[b]);
          }
        }
      if (islast) break;
      if (next.empty()) return {res, btoa};
      for (int a : next) A[a] = lay;
      cur.swap(next);
    }
    /// Usa DFS para escanear caminos aumentantes
    FOR(a, 0, SZ(g))
    res += dfs(dfs, a, 0);
  }
}

int n, m;
vector<string> grid;
vector<vi> g, val, matching, isP;
int c1, c2;

bool isValid(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.');
}

void createGraph(int x, int y, bool p) {
  val[x][y] = (p) ? c1++ : c2++;
  FOR(k, 0, 4) {
    if (isValid(x + dx[k], y + dy[k])) {
      if (val[x + dx[k]][y + dy[k]] == -1)
        createGraph(x + dx[k], y + dy[k], !p);
      if (p) {
        isP[x][y] = 1;
        g[val[x][y]].pb(val[x + dx[k]][y + dy[k]]);
      }
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n >> m;

  grid.resize(n);

  FOR(i, 0, n) {
    cin >> grid[i];
  }

  g.assign(n * m, vi());
  val.assign(n, vi(m, -1));
  matching.assign(n, vi(m, -1));
  isP.assign(n, vi(m, 0));
  c1 = c2 = 0;
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (grid[i][j] == '.' && val[i][j] == -1) {
        createGraph(i, j, 0);
      }
    }
  }

  FOR(x, 0, n) {
    FOR(y, 0, m) {
      if (grid[x][y] == '.') {
        if (isP[x][y]) {
          FOR(k, 0, 4) {
            if (isValid(x + dx[k], y + dy[k])) {
              g[val[x][y]].erase(find(ALL(g[val[x][y]]), val[x + dx[k]][y + dy[k]]));
            }
          }
          matching[x][y] = hopcroftKarp(g, c2).first;

          FOR(k, 0, 4) {
            if (isValid(x + dx[k], y + dy[k])) {
              g[val[x][y]].pb(val[x + dx[k]][y + dy[k]]);
            }
          }
        } else {
          FOR(k, 0, 4) {
            if (isValid(x + dx[k], y + dy[k])) {
              g[val[x + dx[k]][y + dy[k]]].erase(find(ALL(g[val[x + dx[k]][y + dy[k]]]), val[x][y]));
            }
          }
          matching[x][y] = hopcroftKarp(g, c2).first;

          FOR(k, 0, 4) {
            if (isValid(x + dx[k], y + dy[k])) {
              g[val[x + dx[k]][y + dy[k]]].pb(val[x][y]);
            }
          }
        }
      }
    }
  }

  int ans = 0;
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (!isValid(i, j)) continue;
      bool good = 1;
      FOR(k, 0, 4) {
        int ii = i + dx[k], jj = j + dy[k];
        if (isValid(ii, jj) && matching[ii][jj] >= matching[i][j]) {
          good = 0;
        }
      }

      ans += good;
    }
  }
  cout << ans << ENDL;

  return 0;
}