#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};  // abajo, derecha, arriba, izquierda

vector<string> grid;
vector<vi> visited;
int n;

bool isValid(int x, int y) {
  return (x >= 0 && x < 2 && y >= 0 && y < n);
}

void solve() {
  cin >> n;
  grid.resize(2);
  visited.assign(2, vi(n, 0));
  FOR(i, 0, 2) {
    cin >> grid[i];
  }

  queue<pi> q;
  while (SZ(q)) q.pop();
  q.push({0, 0});
  visited[0][0] = 1;
  while (SZ(q)) {
    auto [x, y] = q.front();
    q.pop();
    // cout << "---" << ENDL;
    // cout << x << " " << y << ENDL;
    // cout << "---" << ENDL;

    if (x == 1 && y == n - 1) {
      cout << "YES" << ENDL;
      return;
    }

    FOR(k, 0, 4) {
      int xSig = x + dx[k];
      int ySig = y + dy[k];

      if (isValid(xSig, ySig)) {
        // cout << xSig << " " << ySig << ENDL;
        if (grid[xSig][ySig] == '<') {
          ySig--;
        } else {
          ySig++;
        }

        if (isValid(xSig, ySig) && !visited[xSig][ySig]) {
          visited[xSig][ySig] = 1;
          q.push({xSig, ySig});
        }
      }
    }
  }
  cout << "NO" << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}