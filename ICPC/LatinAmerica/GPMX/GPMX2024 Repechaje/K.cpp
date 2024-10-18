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

  int n, m, o;
  cin >> n >> m >> o;
  vi cnt(n);
  FOR(i, 0, n) cin >> cnt[i];
  vector<vector<pi>> dishes(m);
  FOR(i, 0, m) {
    int ing;
    cin >> ing;
    FOR(j, 0, ing) {
      int idx, c;
      cin >> idx >> c;
      idx--;
      dishes[i].pb({idx, c});
    }
  }
  vector<vi> orders(o);
  FOR(i, 0, o) {
    int x;
    cin >> x;
    while (x--) {
      int y;
      cin >> y;
      y--;
      orders[i].pb(y);
    }
  }
  FOR(i, 0, o) {
    for (auto dish : orders[i]) {
      for (auto ing : dishes[dish]) {
        if (cnt[ing.first] < ing.second) {
          cout << i << ENDL;
          return 0;
        }
        cnt[ing.first] -= ing.second;
      }
    }
  }
  cout << o << ENDL;

  return 0;
}