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

bool compY(pi pt1, pi pt2) { return (pt1.second < pt2.second); }

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n = 5;
  vector<pi> a(n);
  FOR(i, 0, n) cin >> a[i].first >> a[i].second;
  int ans = 0;
  bool continua = 1;
  while (n > 1 && continua) {
    continua = false;

    sort(ALL(a));
    ans += a[1].first - a[0].first;
    a[0].first = a[1].first;
    ans += a[n - 1].first - a[n - 2].first;
    a[n - 1].first = a[n - 2].first;

    sort(ALL(a), compY);
    ans += a[1].second - a[0].second;
    a[0].second = a[1].second;
    ans += a[n - 1].second - a[n - 2].second;
    a[n - 1].second = a[n - 2].second;
    FOR(i, 0, n) {
      FOR(j, 0, i) {
        if (a[i] == a[j]) {
          a.erase(a.begin() + i);
          continua = true;
          n--;
        }
      }
    }
  }

  int xmin = 1e9, xmax = -1, ymin = 1e9, ymax = -1;
  FOR(i, 0, n) {
    xmin = min(xmin, a[i].first);
    xmax = max(xmax, a[i].first);
    ymin = min(ymin, a[i].second);
    ymax = max(ymax, a[i].second);
  }

  // Rectangulo
  ans += (xmax - xmin) * (1 + (ymin != ymax));
  ans += (ymax - ymin) * (1 + (xmin != xmax));

  // Medio
  FOR(i, 0, n) {
    if (a[i].first != xmin && a[i].first != xmax && a[i].second != ymin &&
        a[i].second != ymax)
      ans += min(xmax - xmin, ymax - ymin);
  }
  cout << ans << ENDL;

  return 0;
}