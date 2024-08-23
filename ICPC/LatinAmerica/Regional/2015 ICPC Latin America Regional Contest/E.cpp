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

int n, m, r, b;
vi g[200];
int vis[200];
int cc = 0;
int costo[200];
int cntA[200], cntB[200];
int A[100], B[100];
int dp[200][10001][2];

void dfs(int u) {
  vis[u] = 1;
  costo[cc] += (u < n ? A[u] : B[u - n]);
  cntA[cc] += (u < n);
  cntB[cc] += (u >= n);
  for (auto v : g[u]) {
    if (!vis[v]) dfs(v);
  }
}

int solve(int i, int b, int lado) {
  if (i == cc) return 0;
  int &ans = dp[i][b][lado];
  if (ans != -1) return ans;
  ans = solve(i + 1, b, lado);
  int ganancia = (lado * 2 - 1) * (cntA[i] - cntB[i]);
  int resto = b - costo[i];
  if (ganancia > 0 && resto >= 0)
    ans = max(ans, solve(i + 1, resto, lado) + ganancia);
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m >> r >> b;

  FOR(i, 0, n) cin >> A[i];
  FOR(i, 0, m) cin >> B[i];
  FOR(i, 0, r) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v + n);
    g[v + n].pb(u);
  }

  FOR(i, 0, n + m) {
    if (vis[i]) continue;
    dfs(i);
    cc++;
  }
  memset(dp, -1, sizeof(dp));
  int gN = solve(0, b, 0);
  int gM = solve(0, b, 1);
  cout << n + gN << " " << m + gM << ENDL;
  return 0;
}