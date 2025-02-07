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

const int MAX = 1 << 20;

int dp1[MAX * 2][21], dp2[MAX * 2][21], cnt[MAX * 2];
signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  FOR(i, 1, MAX) {
    dp1[i][0] = cnt[i];
    if (i & 1) dp1[i][0] += cnt[i ^ 1];
    FOR(k, 1, 21) {
      dp1[i][k] = dp1[i][k - 1];
      if ((i >> k) & 1) dp1[i][k] += dp1[i ^ (1 << k)][k - 1];
    }
  }

  ROF(i, MAX + 1, 0) {
    dp2[i][0] = cnt[i];
    if (!(i & 1)) dp2[i][0] += cnt[i xor 1];
    FOR(k, 1, 21) {
      dp2[i][k] = dp2[i][k - 1];
      if (!((i >> k) & 1)) dp2[i][k] += dp2[i xor (1 << k)][k - 1];
    }
  }

  FOR(i, 0, n) {
    cout << dp1[a[i]][20] << " " << dp2[a[i]][20] << " "
         << n - dp1[a[i] ^ (MAX - 1)][20] << ENDL;
  }

  return 0;
}