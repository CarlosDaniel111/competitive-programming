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

constexpr int MAX = 2e5 + 5;

int cnt[MAX];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, sum = 0, g = 0;
  cin >> n;
  vi a(n);
  bool hay0 = false;
  FOR(i, 0, n) {
    int y;
    cin >> a[i] >> y;
    sum += a[i];
    g = gcd(g, y);
    if (a[i] == 0) hay0 = true;
    cnt[a[i]]++;
  }
  if (n == 1) {
    cout << "N" << ENDL;
    return 0;
  }

  bitset<MAX> dp;
  dp[0] = 1;
  FOR(i, 1, sum + 1) {
    if (!cnt[i]) continue;
    for (int x = 0; (1 << x) <= cnt[i]; x++) {
      dp |= (dp << (i * (1 << x)));
      cnt[i] -= (1 << x);
    }
    dp |= (dp << (i * cnt[i]));
  }

  FOR(i, !hay0, sum) {
    if (!dp[i]) continue;
    int diff = abs(i - (sum - i));
    if (diff % g == 0) {
      cout << "Y" << ENDL;
      return 0;
    }
  }
  cout << "N" << ENDL;

  return 0;
}