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

  int t;
  cin >> t;
  vector<vi> start(t);
  map<int, int> bucket;
  int cnt1 = 0;
  FOR(i, 0, t) {
    int m;
    cin >> m;
    cnt1 += m;
    while (m--) {
      int x;
      cin >> x;
      bucket[x]++;
      start[i].pb(x);
    }
  }
  int cnt2 = 0;
  map<int, int> bucket2;
  vector<vi> end(t);
  FOR(i, 0, t) {
    int m;
    cin >> m;
    cnt2 += m;
    while (m--) {
      int x;
      cin >> x;
      bucket2[x]++;
      end[i].pb(x);
    }
  }

  if (cnt1 != cnt2) {
    cout << "N" << ENDL;
    return 0;
  }

  if (t == 2) {
    for (int i = SZ(start[1]) - 1; i >= 0; i--) start[0].pb(start[1][i]);
    for (int i = SZ(end[1]) - 1; i >= 0; i--) end[0].pb(end[1][i]);
    for (int i = 0; i < SZ(start[0]); i++) {
      if (start[0][i] != end[0][i]) {
        cout << "N" << ENDL;
        return 0;
      }
    }
    cout << "S" << ENDL;
    return 0;
  }
  for (auto [x, y] : bucket) {
    if (bucket2[x] != y) {
      cout << "N" << ENDL;
      return 0;
    }
  }
  cout << "S" << ENDL;

  return 0;
}