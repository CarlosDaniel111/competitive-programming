#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, k;
  cin >> n >> k;
  vi a(n), b(n);
  FOR(i, 0, n) cin >> a[i];
  FOR(i, 0, n) cin >> b[i];
  sort(ALL(a));
  sort(ALL(b));
  FOR(i, 0, n) {
    if (a[i] + b[i] > k) {
      cout << i << ENDL;
      return 0;
    }
    k -= a[i] + b[i];
  }
  cout << n << ENDL;

  return 0;
}