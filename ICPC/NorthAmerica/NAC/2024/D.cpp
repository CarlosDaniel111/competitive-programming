#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
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
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vi a(n * 2), b(m);
  FOR(i, 0, n) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  FOR(i, 0, m) cin >> b[i];

  auto check = [&]() -> bool {
    FOR(i, 0, n) {
      if (a[i] != b[0]) continue;
      FOR(j, 0, m) {
        if (a[i + j] != b[j]) return false;
      }
      return true;
    }
  };
  if (check()) {
    cout << 1 << ENDL;
    return 0;
  }
  reverse(ALL(b));
  if (check()) {
    cout << 1 << ENDL;
    return 0;
  }
  cout << 0 << ENDL;

  return 0;
}