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
constexpr int MAXN = 2e5 + 5;
int n;
vi a;
int mcd = 0, tot = 0;
vi cnt, dp, last;
queue<int> q[MAXN];
bool hay0 = false;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n;
  a.resize(n);
  cnt.assign(MAXN, 0);
  dp.assign(MAXN, 0);
  last.assign(MAXN, 0);
  FOR(i, 0, n) {
    int x;
    cin >> a[i] >> x;
    if (a[i] == 0) hay0 = true;
    tot += a[i];
    cnt[a[i]]++;
    mcd = gcd(mcd, x);
  }
  if (n == 1) {
    cout << "N" << ENDL;
    return 0;
  }

  dp[0] = 1;
  last[0] = 1;
  FOR(i, 1, tot + 1) {
    if (!cnt[i]) continue;
    q[0].push(0);
    FOR(j, 1, tot + 1) {
      int t = j % i;
      while (SZ(q[t]) && q[t].front() < j - cnt[i] * i) q[t].pop();
      if (SZ(q[t])) dp[j] = 1;
      dp[j] |= last[j];
      if (last[j]) q[t].push(j);
    }
    FOR(j, 0, tot + 1) {
      last[j] = dp[j];
      dp[j] = 0;
    }
    dp[0] = 1;
    FOR(j, 0, i) {
      while (SZ(q[j])) q[j].pop();
    }
  }

  FOR(i, 1, tot) {
    if (!last[i]) continue;
    int diff = abs(i - tot + i);
    if (diff % mcd == 0) {
      cout << "Y" << ENDL;
      return 0;
    }
  }
  if (hay0 && (tot % mcd == 0)) {
    cout << "Y" << ENDL;
  } else {
    cout << "N" << ENDL;
  }

  return 0;
}