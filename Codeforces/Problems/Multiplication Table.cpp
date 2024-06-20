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

  ll n, m, k;
  cin >> n >> m >> k;

  auto can = [&](ll x) -> bool {
    ll sum = 0;
    FOR(i, 1, n + 1) { sum += min(m, (x - 1) / i); }
    return sum < k;
  };

  ll l = 1, r = n * m + 1;
  while (l < r) {
    ll mid = (l + r) / 2;
    if (can(mid)) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  cout << l - 1 << ENDL;

  return 0;
}