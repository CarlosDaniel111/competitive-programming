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
  int n, A, B;
  cin >> n >> A >> B;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  int ans = 0;
  FOR(i, 0, n) {
    int curr = 1e9;
    FOR(_, 0, 2) {
      curr = min(curr, a[i] % A);
      int aux = (a[i] % A + B) % A;
      curr = min(curr, aux);

      swap(A, B);
    }
    ans = max(curr, ans);
  }
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}