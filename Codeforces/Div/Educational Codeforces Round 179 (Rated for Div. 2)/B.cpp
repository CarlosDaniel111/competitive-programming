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

vi fib(100);

void solve() {
  int n, m;
  cin >> n >> m;
  while (m--) {
    vi a(3);
    FOR(i, 0, 3) cin >> a[i];
    sort(ALL(a));
    if (a[0] >= fib[n - 1] && a[2] >= fib[n])
      cout << 1;
    else
      cout << 0;
  }
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  fib[0] = 1;
  fib[1] = 2;
  FOR(i, 2, 100) { fib[i] = fib[i - 1] + fib[i - 2]; }

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}