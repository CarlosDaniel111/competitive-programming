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

constexpr int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

vector<vi> a;
vector<vi> vis;
int n, m;
bool isValid(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]);
}

void dfs(int x, int y) {
  vis[x][y] = 1;
  FOR(k, 0, 4) {
    if (isValid(dx[k] + x, dy[k] + y) && a[x][y] == a[dx[k] + x][dy[k] + y])
      dfs(dx[k] + x, dy[k] + y);
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m;
  a.assign(n, vi(m));
  vis.assign(n, vi(m, 0));
  FOR(i, 0, n) {
    FOR(j, 0, m) { cin >> a[i][j]; }
  }
  ll ans = 5;
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      if (!vis[i][j]) {
        ans++;
        dfs(i, j);
      }
    }
  }

  FOR(i, 1, n) {
    int l = 0, r = 0;
    FOR(j, 0, m) {
      if (a[i][j] > a[i - 1][j]) {
        ans += (a[i][j] <= l || a[i - 1][j] >= r);
        l = a[i - 1][j];
        r = a[i][j];
      } else {
        l = r = 0;
      }
    }
  }

  ROF(i, n - 1, 0) {
    int l = 0, r = 0;
    FOR(j, 0, m) {
      if (a[i][j] > a[i + 1][j]) {
        ans += (a[i][j] <= l || a[i + 1][j] >= r);
        l = a[i + 1][j];
        r = a[i][j];
      } else {
        l = r = 0;
      }
    }
  }

  FOR(j, 1, m) {
    int l = 0, r = 0;
    FOR(i, 0, n) {
      if (a[i][j] > a[i][j - 1]) {
        ans += (a[i][j] <= l || a[i][j - 1] >= r);
        l = a[i][j - 1];
        r = a[i][j];
      } else {
        l = r = 0;
      }
    }
  }

  ROF(j, m - 1, 0) {
    int l = 0, r = 0;
    FOR(i, 0, n) {
      if (a[i][j] > a[i][j + 1]) {
        ans += (a[i][j] <= l || a[i][j + 1] >= r);
        l = a[i][j + 1];
        r = a[i][j];
      } else {
        l = r = 0;
      }
    }
  }

  cout << ans << ENDL;

  return 0;
}