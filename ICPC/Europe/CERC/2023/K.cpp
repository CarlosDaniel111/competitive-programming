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

map<pi, int> id;
int getID(int u, int v) {
  if (id.count({min(u, v), max(u, v)})) return id[{min(u, v), max(u, v)}];
  return id[{min(u, v), max(u, v)}] = SZ(id);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<vi> g(n);
  FOR(i, 0, m) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
    getID(u, v);
  }
  vi par(n);
  vi vis(n, 0);
  int back = -1;
  auto dfs = [&](auto self, int u, int p) -> void {
    vis[u] = 1;
    for (auto v : g[u]) {
      if (v == p) continue;
      if (v == 1 && back == -1) back = u;
      if (vis[v]) continue;
      par[v] = u;
      self(self, v, u);
    }
  };
  dfs(dfs, 1, -1);
  if (back == -1) {
    cout << "No solution" << ENDL;
    return 0;
  }
  vi inCycle(n, 0);
  int u = back;
  while (u != 1) {
    inCycle[u] = 1;
    u = par[u];
  }
  inCycle[u] = 1;

  vi alicePath, bobPath, aliceKeys, bobKeys, drop;
  auto printSolution = [&]() -> void {
    for (auto key : aliceKeys) {
      cout << key << " ";
    }
    cout << ENDL;
    for (auto key : bobKeys) {
      cout << key << " ";
    }
    cout << ENDL;

    for (auto u : alicePath) {
      if (u == -1) {
        if (!SZ(drop)) continue;
        cout << "DROP ";
        for (auto d : drop) cout << d << " ";
        cout << ENDL;
        continue;
      }
      cout << "MOVE " << u << ENDL;
    }
    cout << "DONE" << ENDL;

    for (auto u : bobPath) {
      if (u == -1) {
        cout << "GRAB" << ENDL;
        continue;
      }
      cout << "MOVE " << u << ENDL;
    }
    cout << "DONE" << ENDL;
  };
  // Caso B
  if (inCycle[0]) {
    int u = 0;
    while (u != 1) {
      aliceKeys.pb(getID(u, par[u]));
      alicePath.pb(par[u]);
      u = par[u];
    }
    bobKeys.pb(getID(1, back));
    bobPath.pb(back);
    u = back;
    while (u != 0) {
      bobKeys.pb(getID(u, par[u]));
      bobPath.pb(par[u]);
      u = par[u];
    }
    printSolution();
    return 0;
  }

  bool pasaCiclo = false;
  u = 0;
  while (u != 1) {
    pasaCiclo |= inCycle[u];
    u = par[u];
  }

  // Caso A
  if (!pasaCiclo) {
    // CAMINO DE ALICE
    // 0 -> 1
    int u = 0;
    while (u != 1) {
      alicePath.pb(par[u]);
      aliceKeys.pb(getID(u, par[u]));
      drop.pb(getID(u, par[u]));
      u = par[u];
    }
    vi exitToBed(ALL(alicePath));
    exitToBed.pop_back();
    reverse(ALL(exitToBed));
    exitToBed.pb(0);
    // 1 -> z
    alicePath.pb(back);
    aliceKeys.pb(getID(1, back));
    alicePath.pb(-1);
    // z -> 1
    alicePath.pb(1);

    // CAMINO DE BOB
    // 1 -> z
    u = back;
    while (u != 1) {
      bobPath.pb(par[u]);
      bobKeys.pb(getID(u, par[u]));
      u = par[u];
    }
    bobPath.pop_back();
    reverse(ALL(bobPath));
    reverse(ALL(bobKeys));
    bobPath.pb(back);
    bobPath.pb(-1);

    // z -> 1
    u = back;
    while (u != 1) {
      bobPath.pb(par[u]);
      u = par[u];
    }
    // 1->0
    for (auto u : exitToBed) bobPath.pb(u);
    printSolution();
    return 0;
  }

  // Caso C
  // CAMINO DE ALICE
  // 0 -> x
  u = 0;

  while (!inCycle[u]) {
    alicePath.pb(par[u]);
    aliceKeys.pb(getID(u, par[u]));
    drop.pb(getID(u, par[u]));
    u = par[u];
  }
  vi xToBed(ALL(alicePath));
  xToBed.pop_back();
  reverse(ALL(xToBed));
  xToBed.pb(0);
  int x = u;
  alicePath.pb(-1);
  // x -> 1
  while (u != 1) {
    alicePath.pb(par[u]);
    aliceKeys.pb(getID(u, par[u]));
    u = par[u];
  }

  // CAMINO DE BOB
  // 1-z
  bobKeys.pb(getID(1, back));
  bobPath.pb(back);
  u = back;
  // z -> x
  while (u != x) {
    bobPath.pb(par[u]);
    bobKeys.pb(getID(u, par[u]));
    u = par[u];
  }
  bobPath.pb(-1);
  // x -> 0
  for (auto u : xToBed) bobPath.pb(u);
  printSolution();

  return 0;
}