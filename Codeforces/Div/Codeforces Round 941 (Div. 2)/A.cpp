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
  int n, k;
  cin >> n >> k;
  vi cnt(105, 0);
  bool ok = false;
  FOR(i, 0, n) {
    int x;
    cin >> x;
    cnt[x]++;
    if (cnt[x] >= k) ok = true;
  }
  if (ok) {
    cout << k - 1 << ENDL;
  } else {
    cout << n << ENDL;
  }
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