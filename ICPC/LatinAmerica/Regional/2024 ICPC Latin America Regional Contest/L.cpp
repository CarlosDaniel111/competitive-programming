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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, t;
  cin >> n >> t;
  vi R(n), C(n);
  iota(ALL(R), 0);
  iota(ALL(C), 0);
  while (t--) {
    char c;
    int i, j;
    cin >> c >> i >> j;
    i--, j--;
    if (c == 'R')
      swap(R[i], R[j]);
    else
      swap(C[i], C[j]);
  }
  vi vis(n, 0);
  int K = -1;
  vector<vi> idxR;
  FOR(i, 0, n) {
    int curr = i;
    vi idx;
    while (!vis[curr]) {
      vis[curr] = 1;
      idx.pb(curr);
      curr = R[curr];
    }
    if (SZ(idx) == 0) continue;
    idxR.pb(idx);
    if (K == -1) K = SZ(idx);
    if (SZ(idx) != K) {
      cout << "*" << ENDL;
      return 0;
    }
  }
  fill(ALL(vis), 0);
  vector<vi> idxC;
  FOR(i, 0, n) {
    int curr = i;
    vi idx;
    while (!vis[curr]) {
      vis[curr] = 1;
      idx.pb(curr);
      curr = C[curr];
    }
    if (SZ(idx) == 0) continue;
    idxC.pb(idx);
    if (SZ(idx) != K) {
      cout << "*" << ENDL;
      return 0;
    }
  }
  vector<vi> ans(n, vi(n));
  FOR(i, 0, SZ(idxR)) {
    int group = (i * K);
    FOR(j, 0, SZ(idxC)) {
      FOR(ii, 0, K) {
        FOR(jj, 0, K) {
          int x = idxR[i][ii];
          int y = idxC[j][jj];
          ans[x][y] = ((ii - jj + K) % K) + group + 1;
        }
      }
      group = (group + K) % n;
    }
  }
  FOR(i, 0, n) {
    FOR(j, 0, n) { cout << ans[i][j] << " \n"[j == n - 1]; }
  }

  return 0;
}