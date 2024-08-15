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
  vi a(2), b(2);
  cin >> a[0] >> a[1] >> b[0] >> b[1];
  vi perm = {0, 1}, perm2 = {0, 1};
  int ans = 0;
  do {
    do {
      int c1 = a[perm[0]] > b[perm2[0]];
      c1 += (a[perm[1]] > b[perm2[1]]);
      int c2 = a[perm[0]] < b[perm2[0]];
      c2 += (a[perm[1]] < b[perm2[1]]);
      ans += (c1 > c2);
    } while (next_permutation(ALL(perm2)));
  } while (next_permutation(ALL(perm)));
  cout << ans << ENDL;
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