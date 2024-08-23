#include <bits/stdc++.h>
using namespace std;

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

  int n, k;
  cin >> n >> k;
  vi a(n + 1);
  FOR(i, 0, n + 1) {
    cin >> a[i];
  }

  while (k--) {
    double x;
    cin >> x;
    x *= 10;
    vector<pi> alturas(n + 1);
    vector<int> p(n + 1);
    FOR(i, 0, n + 1) {
      alturas[i].first = a[i] - (i * x);
      alturas[i].second = i;
      p[i] = alturas[i].first;
    }
    sort(ALL(alturas));

    int mni = n + 1;
    double ans = 0;
    alturas.pb({0, n + 1});
    FOR(i, 0, n + 1) {
      if (alturas[i].second > alturas[mni].second) {
        int l = alturas[mni].second, r = alturas[i].second;
        double t = 0;
        if (r < n && p[r] != p[r + 1]) {
          t = max(t, abs(1.0 * (p[r] - p[l]) / (p[r + 1] - p[r])));
        }
        if (l > 0 && p[l] != p[l - 1]) {
          t = max(t, abs(1.0 * (p[r] - p[l]) / (p[l] - p[l - 1])));
        }
        t = (t > 1) ? 1 : t;
        ans = max(ans, r - l + t);
      }
      if (alturas[i].second < alturas[mni].second) mni = i;
    }
    cout << setprecision(8) << fixed;
    if (ans == 0)
      cout << -1 << ENDL;
    else
      cout << ans << ENDL;
  }

  return 0;
}