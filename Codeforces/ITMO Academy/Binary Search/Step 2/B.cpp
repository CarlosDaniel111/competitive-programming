#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

vector<int> a;
int n, k;

bool can(double x) {
  int cnt = 0;
  FOR(i, 0, n) {
    cnt += floor(a[i] / x);
  }
  return cnt >= k;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n >> k;
  a.resize(n);
  for (auto &x : a) cin >> x;

  double l = 0, r = 1e8;
  FOR(_, 0, 100) {
    double mid = (l + r) / 2;
    if (can(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << setprecision(20) << l << ENDL;

  return 0;
}