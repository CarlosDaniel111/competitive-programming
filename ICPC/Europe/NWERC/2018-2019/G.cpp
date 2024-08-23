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

  string s;
  cin >> s;
  int x = 0, y = 0, len = 1;
  vector<pi> bloques;
  int i = 0;
  for (char c : s) {
    i++;
    if (c == 'L' || c == 'R') {
      int cnt = 0, mn = 1e9, mx = -1e9;
      for (auto bloque : bloques) {
        if (bloque.second == y) {
          cnt++;
          mn = min(mn, bloque.first);
          mx = max(mx, bloque.first);
        }
      }
      // Ya hay 2 bloques en esa linea X
      if (cnt == 2) {
        if (i == SZ(s)) {
          cout << "impossible" << ENDL;
          return 0;
        }
        if (c == 'L')
          x = mn + 1;
        else
          x = mx - 1;

        continue;
      }
    } else {
      int cnt = 0, mn = 1e9, mx = -1e9;
      for (auto bloque : bloques) {
        if (bloque.first == x) {
          cnt++;
          mn = min(mn, bloque.second);
          mx = max(mx, bloque.second);
        }
      }
      // Ya hay 2 bloques en esa linea Y
      if (cnt == 2) {
        if (i == SZ(s)) {
          cout << "impossible" << ENDL;
          return 0;
        }
        if (c == 'U')
          y = mx - 1;
        else
          y = mn + 1;

        continue;
      }
    }

    // Pone el bloque
    if (c == 'L') {
      x -= len;
      bloques.pb({x - 1, y});
    } else if (c == 'R') {
      x += len;
      bloques.pb({x + 1, y});
    } else if (c == 'U') {
      y += len;
      bloques.pb({x, y + 1});
    } else {
      y -= len;
      bloques.pb({x, y - 1});
    }
    len *= 2;
  }

  cout << -x << " " << -y << ENDL;
  cout << SZ(bloques) << ENDL;
  for (auto bloque : bloques) {
    cout << bloque.first - x << " " << bloque.second - y << ENDL;
  }

  return 0;
}