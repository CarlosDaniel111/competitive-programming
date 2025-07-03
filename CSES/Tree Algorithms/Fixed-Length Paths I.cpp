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

const int MAX = 2e5 + 5;
int n, k;
ll ans = 0;
vi g[MAX];
int sz[MAX], taken[MAX];
int calcsz(int u, int p = -1) {
  sz[u] = 1;
  for (auto v : g[u])
    if (v != p && !taken[v]) sz[u] += calcsz(v, u);
  return sz[u];
}
int mxDepth;
int cnt[MAX];

void marcar(int u, int p, int d, int x) {
  if (d > k) return;
  cnt[d] += x;
  mxDepth = max(mxDepth, d);
  for (auto v : g[u]) {
    if (!taken[v] && v != p) {
      marcar(v, u, d + 1, x);
    }
  }
}
void sumAns(int u, int p, int d) {
  if (d > k) return;
  ans += cnt[k - d];
  for (auto v : g[u]) {
    if (!taken[v] && v != p) {
      sumAns(v, u, d + 1);
    }
  }
}

void dnc(int u) {
  cnt[0] = 1;
  mxDepth = 0;
  for (auto v : g[u]) {
    if (!taken[v]) {
      sumAns(v, u, 1);
      marcar(v, u, 1, 1);
    }
  }
  fill(cnt, cnt + mxDepth + 1, 0);
}

void centroid(int u = 0, int p = -1, int globalSz = -1) {
  if (globalSz == -1) globalSz = calcsz(u);
  for (auto v : g[u])
    if (!taken[v] && sz[v] * 2 >= globalSz) {
      sz[u] = 0;
      centroid(v, p, globalSz);
      return;
    }
  taken[u] = 1;
  dnc(u);
  for (auto v : g[u])
    if (!taken[v]) centroid(v, u);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k;
  FOR(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  centroid();
  cout << ans << ENDL;

  return 0;
}