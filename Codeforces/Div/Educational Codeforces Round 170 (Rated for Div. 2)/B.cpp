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

vi p2;
constexpr int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vi a(n), b(n);
  FOR(i, 0, n) cin >> a[i];
  FOR(i, 0, n) cin >> b[i];

  FOR(i, 0, n) {
    if (a[i] == b[i]) {
      cout << 1 << ENDL;
    } else {
      cout << p2[b[i]] << ENDL;
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  p2.assign(100005, 0);

  p2[0] = 1;
  FOR(i, 1, 100005) {
    p2[i] = p2[i - 1] * 2;
    p2[i] %= MOD;
  }

  int t = 1;
  while (t--) solve();

  return 0;
}