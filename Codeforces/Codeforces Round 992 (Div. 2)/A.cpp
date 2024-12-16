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

int n, k;
vi a;

bool check(int i) {
  FOR(j, 0, n) {
    if (j == i) continue;
    int diff = abs(a[i] - a[j]);
    if (diff % k == 0) return false;
  }
  return true;
}

void solve() {
  cin >> n >> k;
  a.resize(n);
  FOR(i, 0, n) { cin >> a[i]; }

  FOR(i, 0, n) {
    if (check(i)) {
      cout << "YES" << ENDL;
      cout << i + 1 << ENDL;
      return;
    }
  }
  cout << "NO" << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}