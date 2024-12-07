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

  int n, k;
  cin >> n >> k;
  vi a(n);
  FOR(i, 0, n) {
    cin >> a[i];
    a[i]--;
  }

  if (k > 22) {
    set<int> s;
    vi ans;
    vi usados(k, 0);
    FOR(i, 0, n) {
      s.insert(a[i]);
      if (SZ(s) == k) {
        ans.pb(a[i]);
        usados[a[i]] = true;
        s.clear();
        FOR(i, 0, k) {
          if (usados[i]) s.insert(i);
        }
      }
    }

    FOR(i, 0, k) {
      if (!usados[i]) ans.pb(i);
    }
    for (auto x : ans) {
      cout << x + 1 << " ";
    }
    cout << ENDL;
    return 0;
  }

  vector<vi> next(n + 2, vi(k, 0));
  FOR(i, 0, k) next[n][i] = next[n + 1][i] = n;
  ROF(i, n, 0) {
    FOR(j, 0, k) {
      if (a[i] == j)
        next[i][j] = i;
      else
        next[i][j] = next[i + 1][j];
    }
  }
  vi dp((1 << k), -1);
  vi f((1 << k), -1);
  FOR(msk, 0, (1 << k)) {
    FOR(j, 0, k) {
      if (!((msk >> j) & 1)) {
        int nmsk = msk | (1 << j);
        if (next[dp[msk] + 1][j] > dp[nmsk]) {
          f[nmsk] = msk;
          dp[nmsk] = next[dp[msk] + 1][j];
        }
      }
    }
  }

  auto print = [&](auto self, int msk) -> void {
    if (msk == 0) return;
    int ant = f[msk];
    self(self, ant);
    FOR(i, 0, k) {
      if (!((ant >> i) & 1) && ((msk >> i) & 1)) {
        cout << i + 1 << " ";
        return;
      }
    }
  };
  if (dp[(1 << k) - 1] != n)
    cout << "*" << ENDL;
  else
    print(print, (1 << k) - 1);

  return 0;
}