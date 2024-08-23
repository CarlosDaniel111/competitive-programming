#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

ld dp[55][55][55];
int vis[55][55][55];
ll n, c, d;
ld comb[55][55];

void combinatorias() {
  FOR(i, 0, 55) {
    comb[i][0] = comb[i][i] = 1;
    FOR(j, 1, i)
    comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
  }
}

ld solve(int s, int x, int y) {
  if (s == 0 && min(x, y) == 0) return 0;
  ld &ans = dp[s][x][y];
  if (vis[s][x][y] == 1) return ans;
  vis[s][x][y] = 1;
  ans = 1;
  ld nada;
  FOR(i, 0, s + 1) {
    FOR(j, 0, x + 1) {
      FOR(k, 0, y + 1) {
        int total = i + j + k;
        if (total > d) continue;
        ld prob = comb[s][i] * comb[x][j] * comb[y][k] * comb[n - s - x - y][d - total] / comb[n][d];
        if (!total)
          nada = prob;
        else
          ans += prob * solve(s - i, x - j, y - k);
      }
    }
  }
  // cout << dv << ENDL;
  ans /= (1 - nada);
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  combinatorias();
  cin >> n >> d >> c;
  vi a(n + 5, 0);
  int shared = 0;
  FOR(i, 0, c) {
    int x;
    cin >> x;
    a[x] = 1;
  }
  FOR(i, 0, c) {
    int x;
    cin >> x;
    if (a[x]) shared++;
  }
  cout << setprecision(12) << fixed;
  cout << solve(shared, c - shared, c - shared);
  return 0;
}