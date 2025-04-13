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

constexpr ll MOD = 1e9 + 7;

void solve() {
  string s;
  cin >> s;
  ll n = SZ(s);
  map<int, int> mapa;
  mapa[0] = 1;
  int cnt = 0;
  ll ans = 0;
  FOR(i, 0, n) {
    if (s[i] == '0')
      cnt++;
    else
      cnt--;

    if (mapa[cnt] != 0) {
      (ans += mapa[cnt] * (n - i)) %= MOD;
    }
    (mapa[cnt] += (i + 2)) %= MOD;
  }
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}