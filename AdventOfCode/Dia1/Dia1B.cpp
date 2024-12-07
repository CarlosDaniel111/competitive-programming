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

  int x, y;
  vi a, b;
  while (cin >> x >> y) {
    a.pb(x);
    b.pb(y);
  }
  map<int, int> cnt;
  for (auto x : b) {
    cnt[x]++;
  }
  ll ans = 0;
  for (auto x : a) {
    ans += x * cnt[x];
  }
  cout << ans << ENDL;

  return 0;
}