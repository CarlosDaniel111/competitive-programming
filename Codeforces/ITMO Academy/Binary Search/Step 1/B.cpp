#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
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
  vi a(n);
  for (auto &x : a) cin >> x;

  while (k--) {
    int l = -1, r = n;
    ll x;
    cin >> x;
    while (l < r - 1) {
      int mid = (l + r) / 2;
      if (a[mid] <= x) {
        l = mid;
      } else {
        r = mid;
      }
    }
    cout << l + 1 << ENDL;
  }

  return 0;
}