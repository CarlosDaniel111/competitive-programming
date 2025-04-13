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
  vector<pi> a(n);
  FOR(i, 0, n) cin >> a[i].first >> a[i].second;

  sort(ALL(a), [&](pi a, pi b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
  });

  int rmx = -1, ans = 0;
  for (auto [l, r] : a) {
    if (l > rmx) {
      ans++;
      rmx = r;
    } else {
      rmx = min(rmx, r);
    }
  }
  cout << ans << ENDL;

  return 0;
}