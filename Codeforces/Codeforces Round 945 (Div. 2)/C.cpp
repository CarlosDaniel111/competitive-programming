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

void solve() {
  int n;
  cin >> n;
  vi a(n);
  int mx = 0;
  FOR(i, 0, n) {
    cin >> a[i];
    if (a[i] == n) mx = i;
  }
  vi ans(n, -1);
  vi usado(n + 1, 0);
  if (mx % 2 == 0) {
    for (int i = 2; i < n - 1; i += 2) {
      if (a[i] == mx) continue;
      ans[i] = (n + 1) - a[i];
      usado[ans[i]] = true;
    }

    for (int i = 1; i < n - 1; i += 2) {
      ans[i] = (n)-a[i];
      usado[ans[i]] = true;
    }
  } else {
    for (int i = 1; i < n - 1; i += 2) {
      if (a[i] == mx) continue;
      ans[i] = (n + 1) - a[i];
      usado[ans[i]] = true;
    }

    for (int i = 2; i < n - 1; i += 2) {
      ans[i] = (n)-a[i];
      usado[ans[i]] = true;
    }
  }

  FOR(j, 0, n) {
    if (ans[j] == -1) {
      FOR(i, 1, n + 1) {
        if (!usado[i]) {
          ans[j] = i;
          usado[i] = true;
          break;
        }
      }
    }
  }

  FOR(i, 0, n) {
    cout << ans[i] << " ";
  }
  cout << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}