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

constexpr ll MOD = 1e9 + 7;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  vi diff(n + 10, 0);
  diff[1] = 0;
  diff[2] = 0;
  diff[3] = 1;
  diff[4] = 0;
  diff[5] = 1;
  diff[6] = 1;
  diff[7] = 2;

  ll cnt = 2;
  ll aux = 0;
  FOR(i, 8, n + 1) {
    diff[i] = diff[i - 3];
    diff[i + 1] = diff[i] + cnt;
    diff[i] %= MOD;
    diff[i + 1] %= MOD;
    aux++;
    if (aux % 3 == 0) cnt++;
    i++;
  }

  vi ans(n + 10, 0);
  ans[1] = 0;
  ans[2] = 0;
  ans[3] = 1;
  FOR(i, 4, n + 1) {
    ans[i] = ans[i - 1] + diff[i];
    ans[i] %= MOD;
  }

  cout << ans[n] % MOD << ENDL;

  return 0;
}