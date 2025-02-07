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
  vi a(n);
  vi cnt(1e4 + 5, 0);
  FOR(i, 0, n) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int k;
  cin >> k;

  int top = 1;
  ROF(i, 1e4 + 5, 2) {
    if (cnt[i] == 0) continue;
    if (cnt[i] <= k) {
      cnt[max(1, i - 5)] += cnt[i];
      k -= cnt[i];
      cnt[i] = 0;
      if (k == 0) {
        top = i - 1;
        break;
      }
    } else {
      cnt[max(1, i - 5)] += k;
      cnt[i] -= k;
      k = 0;
      top = i;
      break;
    }
  }
  if (k) {
    FOR(i, 0, n) cout << 1 << " ";
    return 0;
  }
  vi ans(n, 0);
  FOR(i, 0, 6) {
    int curr = top - i;
    if (curr == 1) {
      FOR(j, 0, n) {
        if (!ans[j]) ans[j] = 1;
      }
      break;
    }
    ROF(j, n, 0) {
      if (a[j] % 5 != curr % 5) continue;

      if (cnt[curr] == 0) break;

      if (!ans[j] && a[j] >= curr) {
        ans[j] = curr;
        cnt[curr]--;
      }
    }
  }
  FOR(i, 0, n) {
    if (!ans[i]) ans[i] = a[i];
  }

  for (auto x : ans) {
    cout << x << " ";
  }

  return 0;
}