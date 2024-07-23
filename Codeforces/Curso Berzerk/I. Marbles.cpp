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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<pi> input(n);
  bool ganelol = false;
  FOR(i, 0, n) {
    cin >> input[i].first >> input[i].second;
    if (input[i].first == input[i].second) ganelol = true;
  }
  if (ganelol) {
    cout << "Y" << ENDL;
    return 0;
  }

  vector<vi> MEX(105, vi(105, -1));

  auto solve = [&](auto self, int x, int y) -> int {
    int &ans = MEX[x][y];
    if (ans != -1) return ans;

    vi vis(1001, 0);
    FOR(i, 1, x) {
      if (i == y) continue;
      vis[self(self, i, y)] = 1;
    }
    FOR(i, 1, y) {
      if (i == x) continue;
      vis[self(self, x, i)] = 1;
    }
    FOR(i, 1, min(x, y)) {
      vis[self(self, x - i, y - i)] = 1;
    }

    FOR(i, 0, 1001) {
      if (!vis[i]) {
        ans = i;
        return ans;
      }
    }
  };

  int sum_xor = 0;
  FOR(i, 0, n)
  sum_xor = sum_xor xor solve(solve, input[i].first, input[i].second);
  if (sum_xor == 0) {
    cout << "N" << ENDL;
  } else {
    cout << "Y" << ENDL;
  }

  return 0;
}