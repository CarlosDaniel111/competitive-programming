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

  int n, m;
  cin >> n >> m;
  int tot = 0;
  vi a(n);
  FOR(i, 0, n) {
    cin >> a[i];
    tot += a[i];
  }
  vi dias(m), val(m);
  FOR(i, 0, m) cin >> dias[i] >> val[i];

  vi sum((1 << m), 0);
  FOR(msk, 0, (1 << m)) {
    FOR(k, 0, m) {
      if ((msk >> k) & 1) sum[msk] += dias[k];
    }
  }

  // Calcular segmentos horizontales
  vi seg;
  FOR(h, 1, m + 1) {
    for (int l = 0, r; l < n; l = r) {
      r = l + 1;
      if (a[l] < h) continue;
      while (r < n && a[r] >= h) r++;
      seg.pb(r - l);
    }
  }
  if (SZ(seg) > m) {
    cout << 0 << ENDL;
    return 0;
  }
  sort(seg.rbegin(), seg.rend());

  vi dp((1 << m), 0), vis((1 << m), 0);
  dp[0] = 1;
  FOR(i, 0, SZ(seg)) {
    ROF(msk, (1 << m), 0) {
      if (dp[msk] && !vis[msk]) {
        vis[msk] = 1;
        int antimsk = ((1 << m) - 1) ^ msk;
        for (int curr = antimsk; curr; curr = (curr - 1) & (antimsk)) {
          if (sum[curr] <= seg[i]) {
            dp[msk | curr] = 1;
          }
        }
      }
    }
  }
  int ans = 0;
  FOR(msk, 0, (1 << m)) {
    if (dp[msk] && sum[msk] == tot) {
      int curr = 0;
      FOR(k, 0, m) {
        if ((msk >> k) & 1) curr += val[k];
      }
      ans = max(ans, curr);
    }
  }
  cout << ans << ENDL;

  return 0;
}