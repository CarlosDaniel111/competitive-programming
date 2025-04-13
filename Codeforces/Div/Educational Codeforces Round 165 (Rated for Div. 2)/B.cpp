#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

void solve() {
  string s;
  cin >> s;
  ll cnt = 1, ans = 0;
  ll mov = 0;
  bool ant = false;
  bool primero = false;
  FOR(i, 0, SZ(s)) {
    if (!primero && s[i] == '0') continue;
    if (s[i] == '1') {
      primero = true;
      ans += (cnt * mov);
      cnt++;
      mov = 0;
    } else {
      mov++;
    }
  }
  ans += (cnt * mov);
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}