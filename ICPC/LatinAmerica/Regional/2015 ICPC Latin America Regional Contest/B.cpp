#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

bool dfs(int a, int L, vi &A, vi &B, vector<vi> &g, vi &btoa) {
  if (A[a] != L) return 0;
  A[a] = -1;
  for (int b : g[a])
    if (B[b] == L + 1) {
      B[b] = 0;
      if (btoa[b] == -1 || dfs(btoa[b], L + 1, A, B, g, btoa)) return btoa[b] = a, 1;
    }
  return 0;
}

pair<int, vi> hopcroftKarp(vector<vi> &g, int m) {
  int res = 0;
  vi btoa(m, -1), A(SZ(g)), B(m), cur, next;
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
    res += dfs(a, 0, A, B, g, btoa);
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  vector<vi> g1(n);
  bool o = false;
  FOR(i, 0, n) {
    int b;
    cin >> b;
    if (b == n) o = true;
    FOR(j, 0, b) {
      int x;
      cin >> x;
      x--;
      g1[i].pb(x);
    }
  }
  while (q--) {
    vi need(n, 0);
    int b;
    cin >> b;
    if (b == 0) {
      cout << (o ? "N" : "Y") << ENDL;
      continue;
    }
    vector<vi> g(n, vi());
    FOR(j, 0, b) {
      int x;
      cin >> x;
      x--;
      need[x] = true;
    }
    FOR(i, 0, n) {
      for (auto u : g1[i]) {
        if (need[u]) g[i].pb(u);
      }
    }

    if (hopcroftKarp(g, n).first == b) {
      cout << "Y" << ENDL;
    } else {
      cout << "N" << ENDL;
    }
  }

  return 0;
}