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
  FOR(i, 0, m) {
    int x, y;
    cin >> x >> y;
    aux = {x, y};
    s.insert({x, y});
  }
  set<pi> ans;

  // 0:up, 1:right, 2:buttom 3:left
  FOR(k, 0, 4) {
    FOR(i, 0, n) {
      int x, y;
      if(k == 0 x = arboles[i] - aux.first, y = arboles[i]-aux.second;
    }
  }

  return 0;
}