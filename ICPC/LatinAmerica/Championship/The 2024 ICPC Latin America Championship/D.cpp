#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
#define __                      \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);

signed main() {
  __
      ll n;
  cin >> n;

  if (n == 1) {
    cout << "N" << ENDL;
    return 0;
  }

  vector<pair<ll, int>> f;
  for (ll i = 2; i * i <= n; i++) {
    int cnt = 0;
    while (n % i == 0) {
      cnt++;
      n /= i;
    }
    if (cnt) f.pb({i, cnt});
  }
  if (n != 1) f.pb({n, 1});

  if ((SZ(f) == 1 && f[0].second % 2 == 1) || (SZ(f) == 2 && f[0].second == 1 && f[1].second == 1)) {
    cout << "Y" << ENDL;
    return 0;
  }
  cout << "N" << ENDL;

  return 0;
}