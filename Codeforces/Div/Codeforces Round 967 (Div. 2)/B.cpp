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
  FOR(i, 1, n + 1) a[i - 1] = i;
  vi ans;
  int mn = 1e9;
  do {
    int cnt1 = 0, i = 0;
    FOR(curr, 1, n + 1) {
      int currid;
      FOR(j, 0, n) if (a[j] == curr) {
        currid = j;
        break;
      }
      if (i > currid) cnt1++;
      i = currid;
    }

    int cnt2 = 0;
    i = n - 1;
    FOR(curr, 1, n + 1) {
      int currid;
      FOR(j, 0, n) if (a[j] == curr) {
        currid = j;
        break;
      }
      if (i < currid) cnt2++;
      i = currid;
    }

    if (cnt1 == cnt2) {
      if (cnt1 < mn) {
        ans = a;
        mn = cnt1;
      }
    }

  } while (next_permutation(ALL(a)));
  cout << mn << ENDL;
  for (auto x : ans) cout << x << " ";
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}