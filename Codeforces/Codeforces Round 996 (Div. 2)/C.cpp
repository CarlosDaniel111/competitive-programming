#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

void solve() {
  ll n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<vi> grid(n, vi(m));
  FOR(i, 0, n) {
    FOR(j, 0, m) { cin >> grid[i][j]; }
  }
  vi sumFila(n, 0);
  FOR(i, 0, n) {
    FOR(j, 0, m) { sumFila[i] += grid[i][j]; }
  }
  vi sumColum(m, 0);
  FOR(i, 0, m) {
    FOR(j, 0, n) { sumColum[i] += grid[j][i]; }
  }
  ll currX = 0, currY = 0;
  vi noseFila(n, 0);
  vi noseColum(m, 0);
  for (auto c : s) {
    noseFila[currX]++;
    noseColum[currY]++;
    if (c == 'R')
      currY++;
    else
      currX++;
  }
  noseFila[currX]++;
  noseColum[currY]++;

  currX = 0, currY = 0;
  for (auto c : s) {
    if (noseFila[currX] == 1) {
      grid[currX][currY] = -sumFila[currX];
      sumColum[currY] += grid[currX][currY];
      noseColum[currY]--;
      noseFila[currX]--;
    } else if (noseColum[currY] == 1) {
      grid[currX][currY] = -sumColum[currY];
      sumFila[currX] += grid[currX][currY];
      noseColum[currY]--;
      noseFila[currX]--;
    }
    if (c == 'R')
      currY++;
    else
      currX++;
  }

  if (noseFila[currX] == 1) {
    grid[currX][currY] = -sumFila[currX];
    sumColum[currY] += grid[currX][currY];
    noseColum[currY]--;
    noseFila[currX]--;
  } else if (noseColum[currY] == 1) {
    grid[currX][currY] = -sumColum[currY];
    sumFila[currX] += grid[currX][currY];
    noseColum[currY]--;
    noseFila[currX]--;
  }

  FOR(i, 0, n) {
    FOR(j, 0, m) { cout << grid[i][j] << " "; }
    cout << ENDL;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}