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

  int n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n) { cin >> a[i]; }

  a.pb(0);
  sort(ALL(a));
  a.erase(unique(ALL(a)), a.end());
  ll cnt = 0;
  FOR(i, 0, SZ(a) - 1) {
    if (a[i + 1] - a[i] == 1)
      cnt++;
    else
      break;
  }
  if (cnt % 2 == 0) {
    if (cnt != SZ(a) - 1) {
      cout << "Alicius" << ENDL;
    } else {
      cout << "Bobius" << ENDL;
    }

  } else {
    if (cnt != SZ(a) - 1) {
      cout << "Bobius" << ENDL;
    } else {
      cout << "Alicius" << ENDL;
    }
  }

  return 0;
}