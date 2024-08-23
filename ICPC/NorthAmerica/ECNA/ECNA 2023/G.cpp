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
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, m, r;
  cin >> n >> m >> r;
  vector<pi> arboles(n);
  FOR(i, 0, n)
  cin >> arboles[i].first >> arboles[i].second;
  set<pi> s;
  pi aux;
  bool que = false;
  FOR(i, 0, m) {
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) que = true;
    aux = {x, y};
    s.insert({x, y});
  }
  if (que) {
    cout << "Impossible" << ENDL;
    return 0;
  }
  set<pi> ans;

  // 0:up, 1:right, 2:buttom 3:left
  FOR(k, 0, 4) {
    FOR(i, 0, n) {
      int x, y;
      if (k == 0)
        x = arboles[i].first - aux.first, y = arboles[i].second - aux.second;
      else if (k == 1)
        x = arboles[i].first + aux.second, y = arboles[i].second - aux.first;
      else if (k == 2)
        x = arboles[i].first + aux.first, y = arboles[i].second + aux.second;
      else
        x = arboles[i].first - aux.second, y = arboles[i].second + aux.first;

      bool puede = true;
      int cnt = 0;
      FOR(j, 0, n) {
        int dx, dy;
        if (k == 0)
          dx = arboles[j].first - x, dy = arboles[j].second - y;
        else if (k == 1)
          dy = x - arboles[j].first, dx = arboles[j].second - y;
        else if (k == 2)
          dx = x - arboles[j].first, dy = y - arboles[j].second;
        else
          dy = arboles[j].first - x, dx = y - arboles[j].second;

        if (s.count({dx, dy}))
          cnt++;
        else if (abs(dx) + abs(dy) <= r) {
          puede = false;
          break;
        }
      }
      if (cnt == m && puede) {
        if (SZ(ans)) {
          cout << "Ambiguous" << ENDL;
          return 0;
        }
        ans.insert({x, y});
      }
    }
  }

  if (!SZ(ans)) {
    cout << "Impossible" << ENDL;
  } else {
    cout << (*ans.begin()).first << " " << (*ans.begin()).second << ENDL;
  }

  return 0;
}