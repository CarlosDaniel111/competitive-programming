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

  string A, B;
  cin >> A >> B;
  int x = SZ(A);
  int y = SZ(B);
  vi a(x), b(y);
  FOR(i, 0, SZ(A)) a[i] = A[i] - '0';
  FOR(i, 0, SZ(B)) b[i] = B[i] - '0';
  reverse(ALL(a)), reverse(ALL(b));
  if (SZ(a) > SZ(b)) swap(a, b);
  while (SZ(a) < SZ(b)) a.pb(0);
  int n = SZ(a);

  int last = -1;
  int carry = 0;
  FOR(i, 0, n) {
    int sum = a[i] + b[i] + carry;
    carry = 0;
    if (sum > 9) {
      last = i;
      carry = 1;
    }
  }

  if (last == -1) {
    cout << 0 << ENDL;
    return 0;
  }
  bool cambio = false;
  ROF(i, last + 1, 0) {
    if (a[i] < b[i]) {
      cambio = true;
      break;
    }
    if (a[i] > b[i]) break;
  }
  if (cambio) swap(a, b);
  vi ans(last + 1);
  carry = 0;
  int m = -1;
  FOR(i, 0, last + 1) {
    ans[i] = (carry - a[i]) % 10;
    if (ans[i] < 0) {
      carry = -1;
      ans[i] += 10;
    }
    if (ans[i]) m = i;
  }
  if (m == -1) {
    cout << 0 << ENDL;
    return 0;
  }
  ROF(i, m + 1, 0) cout << ans[i];
  cout << ENDL;

  return 0;
}