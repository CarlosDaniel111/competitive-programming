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

/*
1 3
1 2 - 1
2 5 - 2
2 6 - 3
4 5 - 4
*/

void solve() {
  int n, d, k;
  cin >> n >> d >> k;
  vector<pi> a(k);
  map<int, int> emp, ter;
  FOR(i, 0, k) {
    int l, r;
    cin >> l >> r;
    emp[l]++;
    ter[r]++;
    a[i] = {l, r};
  }
  int curr = 0;
  FOR(i, 1, d + 1) { curr += emp[i]; }
  int mn = curr, mnd = 1, mx = curr, mxd = 1;
  FOR(i, 1, n - d + 1) {
    curr -= ter[i];
    curr += emp[i + d];
    if (curr < mn) {
      mn = curr;
      mnd = i + 1;
    }
    if (curr > mx) {
      mx = curr;
      mxd = i + 1;
    }
  }
  cout << mxd << " " << mnd << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}