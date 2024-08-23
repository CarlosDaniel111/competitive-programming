#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
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
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int k, n;
  cin >> k >> n;
  vi a(k), b(k);
  vi piezas[10];
  FOR(i, 0, k) {
    cin >> a[i];
  }
  FOR(i, 0, k) {
    cin >> b[i];
    piezas[a[i] * b[i]].pb(i + 1);
  }
  int cur = 0;
  int ans[n][3];
  while (cur < n) {
    if (SZ(piezas[9])) {
      int x = piezas[9].back();
      piezas[9].pop_back();
      ans[cur][0] = x;
      ans[cur][1] = x;
      ans[cur][2] = x;
      ans[cur + 1][0] = x;
      ans[cur + 1][1] = x;
      ans[cur + 1][2] = x;
      ans[cur + 2][0] = x;
      ans[cur + 2][1] = x;
      ans[cur + 2][2] = x;
      cur += 3;
      continue;
    }
    if (SZ(piezas[6])) {
      int x = piezas[6].back();
      piezas[6].pop_back();
      ans[cur][0] = x;
      ans[cur][1] = x;
      ans[cur][2] = x;
      ans[cur + 1][0] = x;
      ans[cur + 1][1] = x;
      ans[cur + 1][2] = x;
      cur += 2;
      continue;
    }

    if (SZ(piezas[4])) {
      int cur2 = cur;
      while (SZ(piezas[4])) {
        int x = piezas[4].back();
        piezas[4].pop_back();
        ans[cur2][0] = x;
        ans[cur2 + 1][0] = x;
        ans[cur2][1] = x;
        ans[cur2 + 1][1] = x;
        cur2 += 2;
      }
      while (cur < cur2) {
        if (SZ(piezas[2]) && cur + 2 <= cur2) {
          int x = piezas[2].back();
          piezas[2].pop_back();
          ans[cur][2] = x;
          ans[cur + 1][2] = x;
          cur += 2;
          continue;
        }
        if (SZ(piezas[3]) && cur + 3 <= cur2) {
          int x = piezas[3].back();
          piezas[3].pop_back();
          ans[cur][2] = x;
          ans[cur + 1][2] = x;
          ans[cur + 2][2] = x;
          cur += 3;
          continue;
        }
        if (SZ(piezas[1])) {
          int x = piezas[1].back();
          piezas[1].pop_back();
          ans[cur][2] = x;
          cur++;
          continue;
        }
      }
    }

    if (SZ(piezas[3])) {
      int x = piezas[3].back();
      piezas[3].pop_back();
      ans[cur][0] = x;
      ans[cur][1] = x;
      ans[cur][2] = x;
      cur++;
      continue;
    }

    if (SZ(piezas[2])) {
      if (SZ(piezas[2]) >= 3) {
        int x = piezas[2].back();
        piezas[2].pop_back();
        int y = piezas[2].back();
        piezas[2].pop_back();
        int z = piezas[2].back();
        piezas[2].pop_back();

        ans[cur][0] = x;
        ans[cur + 1][0] = x;

        ans[cur][1] = y;
        ans[cur + 1][1] = y;

        ans[cur][2] = z;
        ans[cur + 1][2] = z;
        cur += 2;
        continue;
      }
      int x = piezas[2].back();
      piezas[2].pop_back();
      ans[cur][0] = x;
      ans[cur][1] = x;
      int y = piezas[1].back();
      piezas[1].pop_back();
      ans[cur][2] = y;
      cur++;
      continue;
    }
    if (SZ(piezas[1])) {
      int x = piezas[1].back();
      piezas[1].pop_back();
      int y = piezas[1].back();
      piezas[1].pop_back();
      int z = piezas[1].back();
      piezas[1].pop_back();
      ans[cur][0] = x;
      ans[cur][1] = y;
      ans[cur][2] = z;
      cur++;
      continue;
    }
  }

  FOR(i, 0, 3) {
    FOR(j, 0, n) {
      cout << ans[j][i] << " ";
    }
    cout << ENDL;
  }

  return 0;
}