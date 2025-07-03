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

  int n;
  cin >> n;
  ll sumA = 0, sumB = 0, mx = 0;
  ll cnt0 = 0;
  FOR(i, 0, n) {
    ll a, b;
    cin >> a >> b;
    sumA += a;
    sumB += b;
    mx = max(mx, a + b);
  }
  cout << 2 * max({mx, sumA, sumB}) - (sumA + sumB) << ENDL;

  return 0;
}