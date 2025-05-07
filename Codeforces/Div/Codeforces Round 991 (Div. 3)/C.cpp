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

vi vis;

bool solve(ll falta, ll cnt2, ll cnt3) {
  if (falta < 0) return false;
  if (falta == 0) return true;
  vis[falta] = 1;
  if (cnt2) {
    ll sig = (falta - 2 + 9) % 9;
    if (!vis[sig] && solve(sig, cnt2 - 1, cnt3)) return true;
  }
  if (cnt3) {
    ll sig = (falta - 6 + 9) % 9;
    if (!vis[sig] && solve(sig, cnt2, cnt3 - 1)) return true;
  }
  return false;
}

void solve() {
  string s;
  cin >> s;
  ll cnt2 = 0, cnt3 = 0;
  ll sum = 0;
  for (auto c : s) {
    cnt2 += (c == '2');
    cnt3 += (c == '3');
    sum += (c - '0');
  }
  if (sum % 9 == 0) {
    cout << "YES" << ENDL;
    return;
  }
  ll falta = 9 - (sum % 9);
  vis.assign(10, 0);
  if (solve(falta, cnt2, cnt3)) {
    cout << "YES" << ENDL;
  } else {
    cout << "NO" << ENDL;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}