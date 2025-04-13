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
  ll n, k;
  cin >> n >> k;
  vi ans;
  int tope = log2(k);
  FOR(i, 0, 21) {
    if (i == tope) continue;
    ans.pb(1 << i);
  }
  ans.pb(k - (1 << tope));
  ans.pb(k + 1);
  ans.pb(k + 1 + (1 << tope));
  cout << SZ(ans) << ENDL;
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << ENDL;
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