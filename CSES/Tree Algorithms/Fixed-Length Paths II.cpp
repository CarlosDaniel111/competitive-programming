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
int s[MAX];
void update(int pos, ll dif) {  // a[pos] += dif
  for (; pos < MAX; pos |= pos + 1) s[pos] += dif;
}
ll query(int pos) {  // sum of values in [0, pos)
  ll res = 0;
  for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
  return res;
}

ll query(int l, int r) { return query(r + 1) - query(l); }

int n, a, b;
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

void marcar(int u, int p, int d) {
  if (d > b) return;
  update(d, 1);
  mxDepth = max(mxDepth, d);
  for (auto v : g[u]) {
    if (!taken[v] && v != p) {
      marcar(v, u, d + 1);
    }
  }
}
void sumAns(int u, int p, int d) {
  if (d > b) return;
  ans += query(max(0, a - d), b - d);
  for (auto v : g[u]) {
    if (!taken[v] && v != p) {
      sumAns(v, u, d + 1);
    }
  }
}

void dnc(int u) {
  mxDepth = 0;
  for (auto v : g[u]) {
    if (!taken[v]) {
      sumAns(v, u, 1);
      marcar(v, u, 1);
    }
  }
  for (int i = 1; i <= mxDepth; i++) update(i, -query(i, i));
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
  cin >> n >> a >> b;
  update(0, 1);
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