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

  int n;
  cin >> n;
  unordered_map<int, int> mp;
  FOR(i, 0, n) {
    int x;
    cin >> x;
    mp[x]++;
    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        mp[i]++;
        if (x / i != i) mp[x / i]++;
      }
    }
  }
  int aux;
  int mx = 0;
  for (auto [x, y] : mp) {
    if (y >= 2 && x > mx) {
      aux = y;
      mx = x;
    }
  }
  if (mx == 0 || aux == n) {
    cout << "YES" << ENDL;
  } else {
    cout << "NO" << ENDL;
  }

  return 0;
}