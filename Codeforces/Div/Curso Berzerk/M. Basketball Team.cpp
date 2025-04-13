#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, m, h;
  cin >> n >> m >> h;
  vi a(m);
  int suma = 0;
  FOR(i, 0, m) {
    cin >> a[i];
    suma += a[i];
  }
  if (suma < n) {
    cout << "-1" << ENDL;
    return 0;
  }
  h--;
  double ans = 1;
  FOR(i, 0, a[h] - 1) { ans *= (suma - n - i) * 1.0 / (suma - i - 1) * 1.0; }
  cout << setprecision(9) << fixed;
  cout << 1.0 - ans << ENDL;

  return 0;
}